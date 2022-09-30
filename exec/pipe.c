# include "../includes/minishell.h"

static int	split_args(t_cmd **cmd, int *index)
{
	char	**split;
	size_t	i;

	split = ft_split_args((*cmd)->cmd[*index]);
	if (!split)
		return (0);
	(*cmd)->cmd = ft_replace_arr((*cmd)->cmd, split, *index, 1);
	if (!(*cmd)->cmd)
		return (ft_free_2d(split), 0);
	i = 0;
	while (i < ft_arrlen(split))
	{
		(*cmd)->cmd[*index] = ft_remove_quotes((*cmd)->cmd[*index]);
		i ++;
		*index += 1;
	}
	*index -= 1;
	split = ft_free_2d(split);
	return (1);
}

static void	expand_args(t_cmd **cmd)
{
	t_cmd	*t_cmd;
	int		i;

	t_cmd = *cmd;
	i = 0;
	while (t_cmd->cmd[i])
	{
		if (!split_args(&t_cmd, &i))
			return ;
		i ++;
	}
}

char	*get_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	if (!path)
		error_msg(2, cmd);
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
	return (NULL);
}

void	error_msg(int n, char *cmd)
{
	if (n == 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (n == 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	exit(1);
}

void ft_execute(t_cmd *a, char **path)
{
	char	*cmd_path;

	if (access(a->cmd[0], F_OK) == 0)
	{
		if (execve(a->cmd[0], a->cmd, NULL))
		{
			perror("minishell");
			exit(1);
		}
	}
	cmd_path = get_path(path, a->cmd[0]);
	if (!cmd_path)
		error_msg(1, a->cmd[0]);
	if (execve(cmd_path, a->cmd, NULL))
	{
		perror("minishell");
		exit(1);
	}
	exit(0);
}

void	check_path(char *cmd)
{
	int i;

	i = 0;
	g_glob.path_cmd = NULL;
	while (g_glob.env[i])
	{
		if (!ft_strncmp(g_glob.env[i], "PATH", 4))
			break ;
		i++;
	}
	if (!g_glob.env[i])
	{
		error_msg(2, cmd);
	}
	g_glob.path_cmd = ft_split(g_glob.env[i] + 5, ':');
}

void	exec_cmd(t_vars *vars)
{
	int	id;

	expand_args(&vars->cmds);
	if (is_builtin(vars->cmds))
		return ;
	id = fork();
	if (id == 0)
	{
		if (vars->cmds->in)
		{
			dup2(vars->cmds->in, 0);
			close(vars->cmds->in);
		}
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		check_path(vars->cmds->cmd[0]);
		ft_execute(vars->cmds, g_glob.path_cmd);
		ft_free_2d(g_glob.path_cmd);
	}
	if (vars->cmds->in)
		close(vars->cmds->in);
	wait(NULL);
}

int	lst_size(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	i = 0;
	while (tmp)
	{
		tmp  = tmp->next;
		i++;
	}
	return (i);
}

void	exec_pipe(t_vars *vars)
{
	int		count;
	int		(*fd)[2];
	int		i;
	int		start;
	int		end;
	t_cmd	*cmd;

	start = 0;
	end = 0;
	count = lst_size(vars->cmds) - 1;
	fd = malloc(count * sizeof(int*));
	i = 0;
	cmd = vars->cmds;
	while (cmd)
	{
		if (i < count)
		{
			pipe(fd[i]);
			end++;
			if (i && !(i % 2))
			{
				close(fd[start][0]);
				close(fd[start][1]);
				start++;
			}
		}
		if (fork() == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			signal(SIGINT, SIG_DFL);
			if (!i)
				dup2(fd[0][1], 1);
			else if (i == count)
				dup2(fd[i - 1][0], 0);
			else
			{
				dup2(fd[i - 1][0], 0);
				dup2(fd[i][1], 1);
			}
			while (start < end)
			{
				close(fd[start][0]);
				close(fd[start][1]);
				start++;
			}
			if (is_builtin(cmd))
				exit(0);
			check_path(cmd->cmd[0]);
			ft_execute(cmd, g_glob.path_cmd);
		}
		i++;
		cmd = cmd->next;
	}
	while(start < end)
	{
		close(fd[start][0]);
		close(fd[start][1]);
		start++;
	}
	while (wait(NULL) != -1);
}

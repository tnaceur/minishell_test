# include "../includes/minishell.h"

char	*get_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
	return (path[i]);
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
	if (execve(cmd_path, a->cmd, NULL))
	{
		perror("minishell");
		exit(1);
	}
}

void	exec_cmd(t_vars *vars)
{
	int	id;

	id = fork();
	if (id == 0)
		ft_execute(vars->cmds, vars->path_cmd);
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
	int		*fd[2];
	int		i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	count = lst_size(vars->cmds) - 1;
	*fd = malloc((count) * sizeof(int*)); 
	i = 0;
	t_cmd *a = vars->cmds;
	i = 0;
	while (a)
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
			if (!i)
				dup2(fd[0][1], 1);
			else if (i == count)
				dup2(fd[i - 1][0], 0);
			else
			{
				dup2(fd[i - 1][0], 0);
				dup2(fd[i + 1][1], 1);
			}
			while (start < end)
			{
				close(fd[start][0]);
				close(fd[start][1]);
				start++;
			}
			ft_execute(a, vars->path_cmd);
		}
		i++;
		a = a->next;
	}
	wait(NULL);
}

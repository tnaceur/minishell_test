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

void ft_execute(t_vars *vars)
{
	char	*cmd_path;
	t_cmd	*a;
	a = vars->cmds;
	while (a)
	{
		int id = fork();
		if (id == 0)
		{
			if (access(a->cmd[0], F_OK) == 0)
			{
				if (execve(a->cmd[0], a->cmd, NULL))
				{
				 	perror("minishell");
					exit(1);
				}
			}
			cmd_path = get_path(vars->path_cmd, a->cmd[0]);
			if (execve(cmd_path, a->cmd, NULL))
			{
				perror("minishell");
				exit(1);
			}
		}
		wait(NULL);
		a = a ->next;
	}
}

void	exec_cmd(t_vars *vars)
{
	ft_execute(vars);
}

void	exec_pipe(t_vars *vars)
{
	int		i;
	int		count;
	t_list	*tmp;

	i = 0;
	count = 0;
	tmp = vars->tokens;
	while (tmp)
	{
		if (tmp->content[0] == '|')
			count++ ;
		tmp = tmp->next;
	}
	// while (count--)
	// {
		ft_execute(vars);
	// }
}

#include "../includes/minishell.h"

int	is_builtin(t_cmd *vars)
{
	if (!ft_strcmp(vars->cmd[0], "exit"))
	{
		builtin_exit(vars->cmd);
		return (1);
	}
	else if (!ft_strcmp(vars->cmd[0], "env"))
	{
		builtin_env(vars->cmd);
		return (1);
	}
	else if (!ft_strcmp(vars->cmd[0], "echo"))
	{
		builtin_echo(vars->cmd);
		return (1);
	}
	else if (!ft_strcmp(vars->cmd[0], "cd"))
	{
		exec_cd(vars->cmd + 1);
		return (1);
	}
	return (0);
}

void	exec(t_vars *vars)
{
	int	pipe;
	t_list	*tmp;

	pipe = 0;
	tmp = vars->tokens;
	while (tmp)
	{
		if (tmp->content[0] == '|')
			pipe++;
		tmp = tmp->next;
	}
	if (pipe == 0)
		exec_cmd(vars);
	else
		exec_pipe(vars);
}
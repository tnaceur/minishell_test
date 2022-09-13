#include "../includes/minishell.h"

void	exec(t_vars *vars)
{
	int	pipe;
	t_list	*tmp;

	pipe = 0;
	tmp = vars->tokens;
	if (!ft_strcmp(vars->cmds->cmd[0], "exit"))
	{
		builtin_exit(vars->cmds->cmd);
		return ;
	}
	else if (!ft_strcmp(vars->cmds->cmd[0], "env"))
	{
		builtin_env(vars->envp);
		return ;
	}
	else if (!ft_strcmp(vars->cmds->cmd[0], "echo"))
	{
		builtin_echo(vars->cmds->cmd);
		return ;
	}
	else if (!ft_strcmp(vars->cmds->cmd[0], "cd"))
	{
		exec_cd(vars->cmds->cmd + 1);
		return ;
	}
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
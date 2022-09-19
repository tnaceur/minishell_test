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
		exec_cd(vars->cmd);
		return (1);
	}
	else if (!ft_strcmp(vars->cmd[0], "pwd"))
	{
		builtin_pwd();
		return (1);
	}
	else if (!ft_strcmp(vars->cmd[0], "unset"))
	{
		builtin_unset(vars->cmd, &g_glob.env);
		return (1);
	}
	return (0);
}

void	exec(t_vars *vars)
{
	if (!vars->cmds->next)
		exec_cmd(vars);
	else
		exec_pipe(vars);
}
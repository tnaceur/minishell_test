/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:55:48 by sergio            #+#    #+#             */
/*   Updated: 2022/07/22 15:08:26 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	exec_herdoc(t_vars *vars)
{
	t_list	*tmp;
	char	*concatinate;
	char	*herdoc;
	int		fd_herdoc[2];

	tmp = vars->tokens;
	herdoc = NULL;
	concatinate = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "<<") && tmp->next)
		{
			tmp = tmp->next;
			concatinate = readline(">");
			if (!concatinate)
				return ;
			if (herdoc)
			{
				free(herdoc);
				herdoc = NULL;
			}
			while (ft_strcmp(concatinate, tmp->content))
			{
				herdoc = ft_strjoin(herdoc, concatinate);
				herdoc = ft_strjoin(herdoc, "\n");
				free(concatinate);
				concatinate = readline(">"); 
				if (concatinate == NULL)
				{
					free(concatinate);
					return ;
				}
			}
			free(concatinate);
		}
		tmp = tmp->next;
	}
	if (herdoc)
	{
		pipe(fd_herdoc);
		ft_putstr_fd(herdoc, fd_herdoc[1]);
		vars->cmds->in = fd_herdoc[0];
		free(herdoc);
		close(fd_herdoc[1]);
		return ;
	}
	vars->cmds->in = 0;
}

void	continue_parse(t_vars *vars)
{
	t_cmd	*cmd;
	int		i;

	cmd = vars->cmds;
	i = 0;
	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
		{
			if (cmd->cmd[i][0] == '$' && is_env_var(cmd->cmd[i] + 1) != -1)
				cmd->cmd[i] = ft_strdup(g_glob.env[is_env_var(cmd->cmd[i] + 1)] + ft_strlen(cmd->cmd[i]));
			i++;
		}
		cmd = cmd->next;
	}

}

static int ft_loop_cmd(t_vars *vars)
{
    ft_lstclear(&vars->tokens);
    ft_cmd_lstclear(&vars->cmds);
   	vars->cmdline = ft_free(vars->cmdline);
	signal(SIGINT, signals_handler);
    vars->cmdline = readline(PROMPT);
	signal(SIGINT, signal_1);
    if (!vars->cmdline)
		return (0);
    if (vars->cmdline[0] && (!vars->last_cmdline || (vars->last_cmdline
				&& ft_strcmp(vars->cmdline, vars->last_cmdline))))
	{
		vars->last_cmdline = ft_free(vars->last_cmdline);
		vars->last_cmdline = ft_strdup(vars->cmdline);
		add_history(vars->cmdline);
	}
    if (!ft_tokenization(vars) || !ft_lstsize(vars->tokens))
		return (1);
    if (!ft_verify_syntax(vars))
	{
		ft_putendl_fd("MINISHELL$ syntax error.", STDERR_FILENO);
		return (1);
	}
    if (!ft_parse_cmds(vars))
		return (1);
	continue_parse(vars);
	exec_herdoc(vars);
    exec(vars);
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
    t_vars	vars;
	(void)argc;
	(void)argv;
    if (!ft_init_vars(&vars, envp))
        return (EXIT_FAILURE);
    vars.sa.sa_handler = signals_handler;
    vars.sa.sa_flags = 0;
    g_glob.is_child = 0;
	signal(SIGQUIT, SIG_IGN);
    while (ft_loop_cmd(&vars))
    {
		// while (vars.cmds)
		// {
			// int	i = 0;
			// t_cmd *cmd = vars.cmds;
			// while (cmd)
			// {
			// 	printf("cmd : %s\n%p\n", cmd->cmd[i], cmd->cmd[i]);
			// 	cmd = cmd->next;
			// }
		// 	if (vars.cmds->redirect)
		// 	{
		// 		printf("redirect : %s\n", vars.cmds->redirect->content);
		// 		printf("redirect : %d\n", vars.cmds->redirect->type);
		// 	}
		// 	vars.cmds->redirect = vars.cmds->redirect->next;
		// 	vars.cmds = vars.cmds->next;
		// }
		// printf("%s\n", vars.cmdline);
        // t_list  *tmp = vars.tokens;
		// while (tmp)
		// {
		//     printf("token : %s  type : %d\n", tmp->content, tmp->type);
		// 	tmp = tmp->next;
		// }
    };
    ft_free_program(&vars);
    ft_putendl_fd("exit", STDOUT_FILENO);
	return (g_glob.exit_status);
}
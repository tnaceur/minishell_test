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
	// int		fd;
	char	*concatinate;
	char	*herdoc;

	tmp = vars->tokens;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, "<<") && tmp->next)
		{
			tmp = tmp->next;
			concatinate = readline(">");
			if (!concatinate)
				return ;
			while (ft_strcmp(concatinate, tmp->content))
			{
				herdoc = ft_strjoin(herdoc, concatinate);
				herdoc = ft_strjoin(herdoc, "\n");
				concatinate = readline(">"); 
				if (concatinate == NULL)
					return ;
			}
			free(concatinate);
		}
		tmp = tmp->next;
	}
	// printf("%s", herdoc);
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
	exec_herdoc(vars);
    exec(vars);
    return (1);
}

void handleSignal(int key)
{
	(void)key;
	if (g_glob.is_child)
	{
		printf("\n");
		return ;
	}
	printf(PROMPT);
	return ;
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
	vars.cmdline = ft_strdup("");
    while (ft_loop_cmd(&vars))
    {
		// while (vars.cmds)
		// {
		// 	int	i = 0;
		// 	while (vars.cmds->cmd[i])
		// 		printf("cmd : %s\n", vars.cmds->cmd[i++]);
		// 	vars.cmds = vars.cmds->next;
		// }
		// printf("%s\n", vars.cmdline);
        // t_list  *tmp = vars.tokens;
		// while (tmp)
		// {
		//     printf("token : %s  type : %d\n", tmp->content, tmp->type);
		// 	tmp = tmp->next;
		// }
		;
    }
    ft_free_program(&vars);
    ft_putendl_fd("exit", STDOUT_FILENO);
	return (g_glob.exit_status);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initvars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:59:05 by sergio            #+#    #+#             */
/*   Updated: 2022/06/30 02:00:10 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_init_vars(t_vars *vars, char *envp[])
{
	int i;

	i = 0;
	vars->cmdline = NULL;
	vars->last_cmdline = NULL;
	vars->tokens = NULL;
	vars->cmds = NULL;
	vars->envp = ft_arrdup(envp);
	g_glob.env = vars->envp;
    if (!vars->envp)
		return (0);
	return (1);
}
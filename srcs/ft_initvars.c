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
	vars->cmdline = NULL;
	vars->last_cmdline = NULL;
	vars->tokens = NULL;
	vars->cmds = NULL;
	g_glob.env = ft_arrdup(envp);
	return (1);
}

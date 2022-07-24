/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:19:18 by sergio            #+#    #+#             */
/*   Updated: 2022/06/11 11:06:32 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_program(t_vars *vars)
{
	vars->cmdline = ft_free(vars->cmdline);
	vars->last_cmdline = ft_free(vars->last_cmdline);
	vars->envp = ft_free_2d(vars->envp);
    ft_lstclear(&vars->tokens);
    ft_cmd_lstclear(&vars->cmds);
}

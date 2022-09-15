/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:35:37 by yel-moum          #+#    #+#             */
/*   Updated: 2022/09/12 23:35:49 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_env(char **envp)
{
	int	i;

	i = 0;
	if (envp[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(envp[1], 2);
		ft_putstr_fd(": permission denied\n", 2);
		return 0;
	}
	envp = g_glob.env;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '='))
			ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}

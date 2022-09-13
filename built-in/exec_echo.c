/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:58:48 by tnaceur           #+#    #+#             */
/*   Updated: 2022/09/13 00:10:20 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_echo_newline(char *cmd)
{
	int	i;

	if (ft_strncmp(cmd, "-n", 2))
		return (0);
	i = 2;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(char **cmd)
{
	int	newline;
	int	i;

	newline = 1;
	i = 1;
	while (cmd[i] && is_echo_newline(cmd[i]))
	{
		newline = 0;
		i++;
	}
	while (cmd[i])
	{
		printf ("%s", cmd[i]);
		if (cmd[i + 1])
			printf (" ");
		i++;
	}
	if (newline)
		printf ("\n");
	return (EXIT_SUCCESS);
}

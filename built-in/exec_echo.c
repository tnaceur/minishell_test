/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:35:08 by tnaceur           #+#    #+#             */
/*   Updated: 2022/09/18 18:35:12 by tnaceur          ###   ########.fr       */
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

int	is_env_var(char *cmd)
{
	int	i;

	i = 0;
	while (g_glob.env[i])
	{
		if (!ft_strncmp(cmd, g_glob.env[i], ft_strlen(cmd))
			&& g_glob.env[i][ft_strlen(cmd)] == '=')
			return (i);
		i++;
	}
	return (-1);
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
		if (cmd[i][0] == '$' && cmd[i][1] && is_env_var(cmd[i] + 1) != -1)
			printf("%s",
				g_glob.env[is_env_var(cmd[i] + 1)] + ft_strlen(cmd[i]));
		else if ((cmd[i][0] == '$' && !cmd[i][1]) || cmd[i][0] != '$')
			printf ("%s", cmd[i]);
		if (cmd[i + 1])
			printf (" ");
		i++;
	}
	if (newline)
		printf ("\n");
	return (EXIT_SUCCESS);
}

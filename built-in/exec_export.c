/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 00:06:36 by tnaceur           #+#    #+#             */
/*   Updated: 2022/09/29 02:49:38 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <string.h>

int	the_sort(char **env)
{
	int i;
	int j;
	int	small;
	char	*tmp;

	i = 0;
	small = 0;
	tmp = NULL;
	j = 0;
	while (env[i])
	{
		j = i + 1;
		if (env[j] && ft_strcmp(env[j], env[i]) < 0)
		{
			tmp = malloc (ft_strlen(env[i]));
			tmp = ft_strdup(env[i]);
			free(env[i]);
			env[i] = ft_strdup(env[j]);
			free(env[j]);
			env[j] = ft_strdup(tmp);
			free(tmp);
			i = 0;
		}
		else
			i++ ;
	}
	return (small);
}

int	ft_search(char *param)
{
	int	i;

	i = 0;
	while (g_glob.env[i])
	{
		if (!ft_strcmp(param, g_glob.env[i]))
			return (1);
		i++;
	}
	return (0);
}

int	exec_export(char **cmd)
{
	int		i;
	char	**expor;

	if (!cmd[1])
	{
		i = 0;
		expor = ft_arrdup(g_glob.env);
		the_sort(expor);
		i = 0;
		while (expor[i])
			printf("declare -x %s\n", expor[i++]);
		ft_free_2d(expor);
		return (1);
	}
	i = 1;
	while (cmd[i])
	{
		if (ft_search(cmd[i]))
			i++;
		else
		{
			g_glob.env[ft_arrlen(g_glob.env) - 1] = ft_strdup(cmd[i]);
			printf("%s\n", g_glob.env[ft_arrlen(g_glob.env) - 1]);
		}
	}
	return (1);
}

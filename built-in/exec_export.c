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
	int big;
	char	*tmp;

	i = 0;
	small = 0;
	big = 0;
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
		i++ ;
	}
	if (ft_strcmp(env[1], env[0]) < 0)
	{
		tmp = malloc (ft_strlen(env[0]));
		tmp = ft_strdup(env[0]);
		free(env[0]);
		env[0] = ft_strdup(env[1]);
		free(env[1]);
		env[1] = ft_strdup(tmp);
		free(tmp);
	}
	return (small);
}

int	exec_export(char **cmd)
{
	int		i;
	char	**expor;

	i = 0;
	(void)cmd;
	expor = ft_arrdup(g_glob.env);
	the_sort(expor);
	i = 0;
	while (expor[i])
		printf("declare -x %s\n", expor[i++]);
	i = 0;
	while (expor[i])
	{
		free(expor[i]);
		i++;
	}
	free(expor);
	return (1);
}

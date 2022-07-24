/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:58:05 by sergio            #+#    #+#             */
/*   Updated: 2022/06/09 22:58:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **array)
{
	char	**new_array;
	int		i;

	new_array = ft_calloc(ft_arrlen(array) + 1, sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			new_array = ft_free_2d(new_array);
			return (NULL);
		}
		i ++;
	}
	return (new_array);
}

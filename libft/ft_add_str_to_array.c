/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:22:45 by sergio            #+#    #+#             */
/*   Updated: 2022/06/27 11:28:54 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_str_to_array(char **array, char *str)
{
	char	**new_array;
	size_t	array_len;
	size_t	i;

	array_len = 0;
	if (array)
		array_len = ft_arrlen(array);
	new_array = (char **) ft_calloc(array_len + 2, sizeof(char *));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < array_len)
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
			return (ft_free_2d(new_array), NULL);
		i ++;
	}
	new_array[i] = ft_strdup(str);
	if (!new_array[i])
		return (ft_free_2d(new_array), NULL);
	array = ft_free_2d(array);
	return (new_array);
}

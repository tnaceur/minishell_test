/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:23:12 by yel-moum          #+#    #+#             */
/*   Updated: 2022/09/16 19:23:23 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_index {
	size_t	i;
	size_t	j;
	size_t	k;
}	t_index;

char	**ft_replace_arr(
	char **arr1, char **arr2, unsigned int start, unsigned int size
	)
{
	char	**arr;
	size_t	arr_len;
	t_index	index;

	if (!arr1 || !arr2)
		return (NULL);
	arr_len = ft_arrlen(arr1) - size + ft_arrlen(arr2);
	arr = ft_calloc(arr_len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	index.i = 0;
	index.j = 0;
	index.k = 0;
	while (index.i < arr_len)
	{
		if (index.i == start)
			index.j += size;
		if (index.i >= start && index.i < start + ft_arrlen(arr2))
			arr[index.i++] = ft_strdup(arr2[index.k++]);
		else
			arr[index.i++] = ft_strdup(arr1[index.j++]);
		if (index.i != 0 && !arr[index.i - 1])
			return (ft_free_2d(arr), NULL);
	}
	return (ft_free_2d(arr1), arr);
}

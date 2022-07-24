/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:52:14 by sergio            #+#    #+#             */
/*   Updated: 2022/06/10 11:55:52 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	*ft_free_2d(char **array)
{
	int	i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

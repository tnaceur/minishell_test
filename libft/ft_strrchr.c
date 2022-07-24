/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:14:59 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/16 22:24:13 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		j;
	char	*ptr;

	j = 0;
	ptr = (char *)s;
	while (ptr[j])
		j++;
	while (j >= 0)
	{
		if (ptr[j] == (char)c)
			return (ptr + j);
		j--;
	}
	return (0);
}

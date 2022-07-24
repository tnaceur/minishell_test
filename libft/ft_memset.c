/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:49:03 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/21 11:54:57 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)b;
	while (i < len)
	{
		dst[i] = c;
		i++ ;
	}
	return (dst);
}

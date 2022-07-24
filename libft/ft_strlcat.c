/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:36:59 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/18 21:45:43 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		len_src += size;
	else
		len_src += len_dst;
	i = 0;
	if (size > len_dst)
	{
		while (src[i] && len_dst + 1 < size)
		{
			dst[len_dst] = src[i];
			len_dst++ ;
			i++ ;
		}
		dst[len_dst] = '\0';
	}
	return (len_src);
}

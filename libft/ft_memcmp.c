/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:14:12 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/15 14:13:22 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*s11;
	unsigned const char	*s22;

	i = 0;
	s11 = s1;
	s22 = s2;
	if (n == 0)
		return (0);
	while (s11[i] == s22[i] && n - 1 > i)
		i++ ;
	return (s11[i] - s22[i]);
}

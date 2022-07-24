/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:05:47 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/18 13:18:56 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	beg;
	unsigned int	end;
	unsigned int	i;
	char			*ptr;

	if (!s1)
		return (0);
	i = 0;
	beg = 0;
	end = ft_strlen(s1);
	while (beg < end && ft_strchr(set, s1[beg]))
		beg++ ;
	while (beg < end && ft_strchr(set, s1[end]))
		end-- ;
	ptr = (char *)malloc((end - beg + 2) * sizeof(char));
	if (!ptr)
		return (0);
	while (end >= beg)
		ptr[i++] = s1[beg++];
	ptr[i] = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:30:31 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/22 13:57:00 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++ ;
	ptr = (char *)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = (*f)(i, (char)s[i]);
		i++ ;
	}
	ptr[i] = '\0';
	return (ptr);
}

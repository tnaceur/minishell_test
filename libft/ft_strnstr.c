/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:56:46 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/15 14:32:40 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && len > i)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++ ;
		}
		i++ ;
	}
	return (0);
}
/*int main(void)
{
    char str[] = "tahaabc";
    char to_find[] = "bc";
    printf("%s\n%s\n", ft_strnstr(str, to_find, 6), strnstr(str, to_find, 6));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:54:51 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/16 15:10:01 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

// static char	*ft_strcat(char *s1, char *s2)
// {
// 	int	i;
// 	int	j;

// 	i = ft_strlen(s1);
// 	j = 0;
// 	while (s2[j])
// 	{
// 		s1[i + j] = s2[j];
// 		j++ ;
// 	}
// 	s1[i + j] = '\0';
// 	return (s1);
// }
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = malloc(i + j + 1);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}
/*int main(void)
{
	char s1[] = "lorem ipsumdolor";
	char s2[] = " sit amet";
	printf("%s\n", ft_strjoin(s1, s2));
}*/

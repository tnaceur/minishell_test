/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:51:38 by sergio            #+#    #+#             */
/*   Updated: 2022/06/10 11:51:44 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arrlen(char **arr)
{
	size_t	arrlen;

	arrlen = 0;
	while (arr[arrlen])
		arrlen ++;
	return (arrlen);
}

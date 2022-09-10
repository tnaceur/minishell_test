/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:58:48 by tnaceur           #+#    #+#             */
/*   Updated: 2022/09/10 14:46:43 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	//while (1)
	//{
		char	*token = argv[1];
		int		i;
		int		count;
		int		j;
		
		i = 0;
		j = 0;
		count = 0;
		while (token[i])
		{
			if (token[i + 1] && token[i + 2] && token[i] == '-'
				&& token[i + 1] == 'n' && token[i + 2] == ' ')
			{
				count++;
				j = i + 3;
			}
			i++;
		}
		if (count >= 1)
		{
			token += j;
			printf("%s", token);
		}
		else
			printf("%s\n", token);
	//}
}

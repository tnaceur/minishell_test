/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:35:11 by tnaceur           #+#    #+#             */
/*   Updated: 2022/06/10 11:41:20 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_lstadd_front(t_list2 **alst, t_list2 *new)
{
	new ->next = *alst;
	*alst = new;
}

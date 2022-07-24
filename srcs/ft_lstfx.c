/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:17:15 by sergio            #+#    #+#             */
/*   Updated: 2022/06/21 12:48:01 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*holder;
	
	if(!lst)
		return ;
	while (*lst)
	{
		holder = *lst;
		*lst = (*lst)->next;
		holder->content = ft_free(holder->content);
		holder = ft_free(holder);
	}
	*lst = NULL;
}

t_list	*ft_lstnew(char *content, int type)
{
	t_list	*element;

	element = malloc (1 * sizeof(t_list));
	if (element == NULL)
		return (0);
	element->content = content;
	element->type = type;
	element->next = NULL;
	return (element);
}

int	ft_lstsize(t_list *lst)
{
	int	lstlen;

	lstlen = 0;
	while (lst)
	{
		lst = lst->next;
		lstlen ++;
	}
	return (lstlen);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && *lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

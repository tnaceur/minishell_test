/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_fx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:04:57 by sergio            #+#    #+#             */
/*   Updated: 2022/06/27 11:40:14 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cmd_lstclear(t_cmd **lst)
{
	t_cmd	*holder;

	if (!lst)
		return ;
	while (*lst)
	{
		holder = *lst;
		*lst = (*lst)->next;
		holder->cmd = ft_free_2d(holder->cmd);
		holder->subsh_lvl = ft_free(holder->subsh_lvl);
		ft_lstclear(&holder->redirect);
		holder = ft_free(holder);
	}
	*lst = NULL;
}

t_cmd	*ft_cmd_lstnew(char **cmd, int type, int *subsh_lvl, t_list *redirect)
{
	t_cmd	*element;

	element = malloc (1 * sizeof(t_cmd));
	if (element == NULL)
		return (0);
	element->cmd = cmd;
	element->type = type;
	element->subsh_lvl = subsh_lvl;
	element->redirect = redirect;
	element->next = NULL;
	return (element);
}

t_cmd	*ft_cmd_lstlast(t_cmd *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	ft_cmd_lstadd_back(t_cmd **lst, t_cmd *new)
{
	if (lst && *lst)
		ft_cmd_lstlast(*lst)->next = new;
	else
		*lst = new;
}

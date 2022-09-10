/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_syntax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:37:56 by sergio            #+#    #+#             */
/*   Updated: 2022/07/24 13:05:13 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_verify_quotes(t_vars *vars)
{
    t_syntax	syntax;
	t_list		*t_tokens;

	syntax.s_quotes = 0;
	t_tokens = vars->tokens;
	while (t_tokens)
	{
		if (t_tokens->type == S_QUOTE)
			syntax.s_quotes++;
		t_tokens = t_tokens->next;
	}
	if (syntax.s_quotes % 2 != 0)
		return (0);
	return (1);
}

static int	ft_verify_pipe(t_vars *vars)
{
	t_list		*t_tokens;
	int			is_word;

	is_word = 0;
	t_tokens = vars->tokens;
	while (t_tokens)
	{
		if (t_tokens->type == WORD)
			is_word = 1;
		if (is_word
			&& (t_tokens->type == PIPE))
			is_word = 0;
		else if (!is_word
			&& (t_tokens->type == PIPE))
			return (0);
		t_tokens = t_tokens->next;
	}
	if (!is_word)
		return (0);
	return (1);
}

static int	ft_verify_redirections(t_vars *vars)
{
	t_list		*t_tokens;

	t_tokens = vars->tokens;
	while (t_tokens)
	{
		if ((t_tokens->type == RED_IN
				|| t_tokens->type == RED_OUT
				|| t_tokens->type == D_RED_IN
				|| t_tokens->type == D_RED_OUT)
			&& (!t_tokens->next
				|| (t_tokens->next
					&& t_tokens->next->type != WORD)))
			return (0);
		t_tokens = t_tokens->next;
	}
	return (1);
}

int	ft_verify_syntax(t_vars *vars)
{
	if (!ft_verify_quotes(vars)
		|| !ft_verify_pipe(vars)
		|| !ft_verify_redirections(vars))
		return (0);
	return (1);
}

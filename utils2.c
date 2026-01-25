/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:28:16 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/24 12:28:20 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stk)
{
	t_list	*tmp;

	if (stk)
	{
		while (*stk)
		{
			tmp = (*stk)->next;
			free(*stk);
			*stk = tmp;
		}
	}
}

int	check_is_sort(t_list *stk_a)
{
	while (stk_a && stk_a->next)
	{
		if (stk_a->number > stk_a->next->number)
			return (0);
		stk_a = stk_a->next;
	}
	return (1);
}

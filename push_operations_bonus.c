/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:54:04 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/19 15:02:14 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;

	if (!stk_a || !stk_b || !*stk_b)
		return ;
	tmp = *stk_a;
	*stk_a = *stk_b;
	(*stk_b) = (*stk_b)->next;
	if (*stk_b)
		(*stk_b)->prev = NULL;
	(*stk_a)->next = tmp;
	(*stk_a)->prev = NULL;
	if (tmp)
		tmp->prev = *stk_a;
}

void	pb(t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;

	if (!stk_b || !stk_a || !*stk_a)
		return ;
	tmp = *stk_b;
	*stk_b = *stk_a;
	(*stk_a) = (*stk_a)->next;
	if (*stk_a)
		(*stk_a)->prev = NULL;
	(*stk_b)->next = tmp;
	(*stk_b)->prev = NULL;
	if (tmp)
		tmp->prev = *stk_b;
}

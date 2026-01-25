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

#include "push_swap.h"

void	pa(t_list **stk_a, t_list **stk_b, int is_pr)
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
	if (is_pr)
		write(1, "pa\n", 3);
}

void	pb(t_list **stk_a, t_list **stk_b, int is_pr)
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
	if (is_pr)
		write(1, "pb\n", 3);
}

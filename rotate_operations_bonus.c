/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:03:23 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/19 15:06:19 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_helper(t_list **lst)
{
	t_list	*p1;
	t_list	*last_p;

	p1 = *lst;
	last_p = *lst;
	while (last_p->next != NULL)
		last_p = last_p->next;
	*lst = p1->next;
	(*lst)->prev = NULL;
	p1->prev = last_p;
	last_p->next = p1;
	p1->next = NULL;
}

void	ra(t_list **lst)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	rotate_helper(lst);
}

void	rb(t_list **lst)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	rotate_helper(lst);
}

void	rr(t_list **stk_a, t_list **stk_b)
{
	if (stk_a && *stk_a && (*stk_a)->next)
	{
		rotate_helper(stk_a);
	}
	if (stk_b && *stk_b && (*stk_b)->next)
	{
		rotate_helper(stk_b);
	}
}

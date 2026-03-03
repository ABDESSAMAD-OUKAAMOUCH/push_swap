/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:07:01 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/19 15:12:06 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_helper(t_list **lst)
{
	t_list	*last_p;
	t_list	*first_p;

	last_p = *lst;
	first_p = *lst;
	while (last_p->next != NULL)
		last_p = last_p->next;
	last_p->prev->next = NULL;
	last_p->prev = NULL;
	last_p->next = first_p;
	first_p->prev = last_p;
	*lst = last_p;
}

void	rra(t_list **lst)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	reverse_helper(lst);
}

void	rrb(t_list **lst)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	reverse_helper(lst);
}

void	rrr(t_list **stk_a, t_list **stk_b)
{
	if (stk_a && *stk_a && (*stk_a)->next)
	{
		reverse_helper(stk_a);
	}
	if (stk_b && *stk_b && (*stk_b)->next)
	{
		reverse_helper(stk_b);
	}
}

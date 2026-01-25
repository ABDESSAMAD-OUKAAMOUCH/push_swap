/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:51:28 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/19 14:53:25 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_helper(t_list **lst)
{
	t_list	*parameter1;
	t_list	*parameter2;

	parameter1 = *lst;
	parameter2 = parameter1->next;
	parameter1->next = parameter2->next;
	if (parameter2->next)
		parameter2->next->prev = parameter1;
	parameter2->next = parameter1;
	parameter1->prev = parameter2;
	parameter2->prev = NULL;
	*lst = parameter2;
}

void	sa(t_list **lst, int is_pr)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	swap_helper(lst);
	if (is_pr)
		write(1, "sa\n", 3);
}

void	sb(t_list **lst, int is_pr)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	swap_helper(lst);
	if (is_pr)
		write(1, "sb\n", 3);
}

void	ss(t_list **stk_a, t_list **stk_b, int is_pr)
{
	int	swap;

	swap = 0;
	if (stk_a && *stk_a && (*stk_a)->next)
	{
		swap_helper(stk_a);
		swap = 1;
	}
	if (stk_b && *stk_b && (*stk_b)->next)
	{
		swap_helper(stk_b);
		swap = 1;
	}
	if (swap && is_pr)
		write(1, "ss\n", 3);
}

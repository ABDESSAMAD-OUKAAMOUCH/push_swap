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

#include "push_swap.h"

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

void	ra(t_list **lst, int is_pr)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	rotate_helper(lst);
	if (is_pr)
		write(1, "ra\n", 3);
}

void	rb(t_list **lst, int is_pr)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	rotate_helper(lst);
	if (is_pr)
		write(1, "rb\n", 3);
}

void	rr(t_list **stk_a, t_list **stk_b, int is_pr)
{
	int	rotate;

	rotate = 0;
	if (stk_a && *stk_a && (*stk_a)->next)
	{
		rotate_helper(stk_a);
		rotate = 1;
	}
	if (stk_b && *stk_b && (*stk_b)->next)
	{
		rotate_helper(stk_b);
		rotate = 1;
	}
	if (rotate && is_pr)
		write(1, "rr\n", 3);
}

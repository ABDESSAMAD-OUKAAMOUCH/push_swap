/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:28:39 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/24 12:28:42 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_list *stk_a)
{
	t_list	*max;
	t_list	*tmp;

	tmp = stk_a->next;
	max = stk_a;
	while (tmp)
	{
		if (tmp->index > max->index)
		{
			max = tmp;
		}
		tmp = tmp->next;
	}
	return (max->index);
}

void	push_max_index(t_list **stk_a, t_list **stk_b, int index, int pos)
{
	int	size;

	size = ft_list_size(*stk_b);
	if (pos <= size / 2)
	{
		while ((*stk_b)->index != index)
		{
			rb(stk_b);
		}
	}
	else
	{
		while ((*stk_b)->index != index)
		{
			rrb(stk_b);
		}
	}
	pa(stk_a, stk_b);
}

int	calc_cost(t_list *stk_b, int pos)
{
	int	counter;
	int	cost;

	counter = ft_list_size(stk_b);
	cost = pos;
	if (pos > counter / 2)
		cost = counter - pos;
	return (cost);
}

void	push_to_stk_a(t_list **stk_a, t_list **stk_b)
{
	int	max;
	int	pos_max;
	int	pos_next;
	int	c_m;
	int	c_n;

	while (*stk_b)
	{
		max = max_index(*stk_b);
		pos_max = pos_index(*stk_b, max);
		pos_next = pos_index(*stk_b, max - 1);
		c_m = calc_cost(*stk_b, pos_max);
		c_n = calc_cost(*stk_b, pos_next);
		if (pos_next != -1 && c_m > c_n)
		{
			push_max_index(stk_a, stk_b, max - 1, pos_next);
			pos_max = pos_index(*stk_b, max);
			push_max_index(stk_a, stk_b, max, pos_max);
			sa(stk_a);
		}
		else
			push_max_index(stk_a, stk_b, max, pos_max);
	}
}

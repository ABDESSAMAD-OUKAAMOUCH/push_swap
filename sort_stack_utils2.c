/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:28:52 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/26 10:39:42 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_index(t_list **stk_a, t_list **stk_b, int midd, int *pushed)
{
	int	tmp;
	int	check;

	check = 0;
	tmp = (*stk_a)->index;
	pb(stk_a, stk_b);
	if (tmp < midd)
	{
		check = 1;
	}
	(*pushed)++;
	return (check);
}

void	choose_op(t_list **stk_a, t_list **stk_b, int min, int max)
{
	if (*stk_a && !((*stk_a)->index >= min && (*stk_a)->index <= max))
		rr(stk_a, stk_b);
	else
		rb(stk_b);
}

void	change_chunk(int *pushed, int *current_chu, int chunksize)
{
	if (*pushed == chunksize)
	{
		(*current_chu)++;
		*pushed = 0;
	}
}

void	push_to_stk_b(t_list **stk_a, t_list **stk_b, int chunksize)
{
	int	pushed;
	int	current_chu;
	int	min_ind;
	int	max_ind;
	int	middle_ind;

	pushed = 0;
	current_chu = 0;
	while (*stk_a)
	{
		min_ind = current_chu * chunksize;
		max_ind = min_ind + chunksize - 1;
		middle_ind = (max_ind + min_ind) / 2;
		if ((*stk_a)->index >= min_ind && (*stk_a)->index <= max_ind)
		{
			if (push_index(stk_a, stk_b, middle_ind, &pushed))
				choose_op(stk_a, stk_b, min_ind, max_ind);
			change_chunk(&pushed, &current_chu, chunksize);
		}
		else
			ra(stk_a);
	}
}

void	sort_stack(t_list **stk_a, t_list **stk_b)
{
	int	chunksize;
	int	size;

	size = ft_list_size(*stk_a);
	if (size <= 5)
	{
		if (size == 2)
			sort_two_items(stk_a);
		else if (size == 3)
			sort_three_items(stk_a);
		else
			sort_five_items(stk_a, stk_b);
	}
	else
	{
		if (size <= 100)
			chunksize = 20;
		else
			chunksize = 60;
		push_to_stk_b(stk_a, stk_b, chunksize);
		push_to_stk_a(stk_a, stk_b);
	}
}

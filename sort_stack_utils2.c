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

int	push_chunk(t_list **stk_a, t_list **stk_b, int midd, int *pushed)
{
	int	tmp;
	int	check;

	check = 0;
	tmp = (*stk_a)->index;
	pb(stk_a, stk_b, 1);
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
		rr(stk_a, stk_b, 1);
	else
		rb(stk_b, 1);
}

void	change_chunk(int *pushed, int *current_chunk, int chunksize)
{
	if (*pushed == chunksize)
	{
		(*current_chunk)++;
		*pushed = 0;
	}
}

void	puch_to_b(t_list **stk_a, t_list **stk_b, int chunksize)
{
	int	pushed;
	int	current_chunk;
	int	min_index;
	int	max_index;
	int	middle_index;

	pushed = 0;
	current_chunk = 0;
	while (*stk_a)
	{
		min_index = current_chunk * chunksize;
		max_index = min_index + chunksize - 1;
		middle_index = (max_index + min_index) / 2;
		if ((*stk_a)->index >= min_index && (*stk_a)->index <= max_index)
		{
			if (push_chunk(stk_a, stk_b, middle_index, &pushed))
				choose_op(stk_a, stk_b, min_index, max_index);
			change_chunk(&pushed, &current_chunk, chunksize);
		}
		else
			ra(stk_a, 1);
	}
}

void	sort_stack(t_list **stk_a, t_list **stk_b)
{
	int	chunksize;
	int	counter;

	counter = ft_list_size(*stk_a);
	if (counter <= 5)
	{
		if (counter == 2)
			sort_two_items(stk_a);
		else if (counter == 3)
			sort_three_items(stk_a);
		else
			sort_for_five_items(stk_a, stk_b);
	}
	else
	{
		if (counter <= 100)
			chunksize = 20;
		else
			chunksize = 63;
		puch_to_b(stk_a, stk_b, chunksize);
		push_to_a(stk_a, stk_b);
	}
}

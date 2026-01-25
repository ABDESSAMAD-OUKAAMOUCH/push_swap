/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:28:52 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/24 12:28:56 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_list **stk_a, t_list **stk_b, int midd, int *pushed, int min_index, int max_index)
{
	int	tmp;

	tmp = (*stk_a)->index;
	pb(stk_a, stk_b, 1);
	if (tmp < midd)
	{
		if(*stk_a && !((*stk_a)->index >= min_index && (*stk_a)->index <= max_index))
			rr(stk_a, stk_b, 1);
		else
			rb(stk_b, 1);
			
	}
	(*pushed)++;
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
			push_chunk(stk_a, stk_b, middle_index, &pushed, min_index, max_index);
			if (pushed == chunksize)
			{
				current_chunk++;
				pushed = 0;
			}
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

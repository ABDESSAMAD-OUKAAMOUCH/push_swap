/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:50:57 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/20 14:25:46 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_index(t_list *stk_a, int max)
{
	t_list	*tmp;
	int		i;

	tmp = stk_a;
	i = 0;
	while (tmp)
	{
		if (tmp->index == max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	sort_two_items(t_list **stk_a)
{
	if ((*stk_a)->index > (*stk_a)->next->index)
		sa(stk_a, 1);
}

void	sort_three_items(t_list **stk_a)
{
	if ((*stk_a)->next->index < (*stk_a)->index)
		sa(stk_a, 1);
	if ((*stk_a)->next->index > (*stk_a)->next->next->index)
		rra(stk_a, 1);
	if ((*stk_a)->index > (*stk_a)->next->index)
		sa(stk_a, 1);
}

void	insert_index(t_list **stk_a, int index)
{
	int	size;

	size = ft_list_size(*stk_a);
	if (pos_index(*stk_a, index) <= size / 2)
	{
		while ((*stk_a)->index != index)
		{
			ra(stk_a, 1);
		}
	}else{
		while ((*stk_a)->index != index)
		{
			rra(stk_a, 1);
		}
	}
}

void	sort_for_five_items(t_list **stk_a, t_list **stk_b)
{
	if (ft_list_size(*stk_a) == 5)
	{
		insert_index(stk_a, 0);
		pb(stk_a, stk_b, 1);
		insert_index(stk_a, 1);
		pb(stk_a, stk_b, 1);
		sort_three_items(stk_a);
		pa(stk_a, stk_b, 1);
		pa(stk_a, stk_b, 1);
	}
	else
	{
		insert_index(stk_a, 0);
		pb(stk_a, stk_b, 1);
		sort_three_items(stk_a);
		pa(stk_a, stk_b, 1);
	}
}

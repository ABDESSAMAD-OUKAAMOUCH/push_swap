/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:29:52 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/24 12:30:21 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	free_data(char *line, t_list **stk_a, t_list **stk_b)
{
	free_stack(stk_a);
	free_stack(stk_b);
	free(line);
	print_error();
}

void	check_op(t_list **stk_a, t_list **stk_b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		pa(stk_a, stk_b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stk_a, stk_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stk_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stk_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stk_a, stk_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stk_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stk_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stk_a, stk_b);
	else if (!ft_strcmp(line, "sa\n"))
		sa(stk_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stk_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stk_a, stk_b);
	else
		free_data(line, stk_a, stk_b);
}

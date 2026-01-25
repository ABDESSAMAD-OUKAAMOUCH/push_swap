/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:48:08 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/24 11:55:29 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_op(t_list **stk_a, t_list **stk_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_op(stk_a, stk_b, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	if (argc == 1)
		return (0);
	stk_a = NULL;
	stk_b = NULL;
	is_valid_arg(argv);
	if (!is_unique(argv, argc))
		print_error();
	input_storage(&stk_a, argv);
	get_op(&stk_a, &stk_b);
	if (check_is_sort(stk_a) && !stk_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stk_a);
	return (0);
}

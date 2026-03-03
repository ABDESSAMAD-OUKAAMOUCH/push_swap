/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:33:43 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/24 11:41:19 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index_to_node(int *arr, int size, t_list *stk_a)
{
	int		j;
	t_list	*lst;

	j = 0;
	lst = stk_a;
	while (stk_a && j < size)
	{
		if (stk_a->number == arr[j])
		{
			stk_a->index = j;
			j++;
			stk_a = lst;
		}
		else
		{
			stk_a = stk_a->next;
		}
	}
	free(arr);
}

void	sort_arr(int *arr, int size, t_list *stk_a)
{
	int	i;
	int	current;
	int	j;

	i = 1;
	while (i < size)
	{
		current = arr[i];
		j = i - 1;
		while (j >= 0 && current < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
		i++;
	}
	give_index_to_node(arr, size, stk_a);
}

void	create_sort_arr(t_list **stk_a)
{
	int		i;
	int		*arr;
	int		counter;
	t_list	*tmp;

	i = 0;
	counter = ft_list_size(*stk_a);
	tmp = *stk_a;
	arr = malloc(counter * sizeof(int));
	if (!arr)
	{
		free_stack(stk_a);
		print_error();
	}
	while (tmp)
	{
		arr[i] = tmp->number;
		tmp = tmp->next;
		i++;
	}
	sort_arr(arr, counter, *stk_a);
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
	if (check_is_sort(stk_a))
	{
		free_stack(&stk_a);
		return (0);
	}
	create_sort_arr(&stk_a);
	sort_stack(&stk_a, &stk_b);
	free_stack(&stk_a);
	free_stack(&stk_b);
	return (0);
}

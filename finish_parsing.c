/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:36:02 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/23 14:39:10 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(char **args)
{
	int	j;

	j = 0;
	while (args[j])
		free(args[j++]);
	free(args);
}

void	check_error(char **args)
{
	if (!args || !args[0])
	{
		free_memory(args);
		print_error();
	}
}

void	is_valid_arg(char **argv)
{
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		check_error(args);
		while (args[j])
		{
			if (!check_overflow(args[j]))
			{
				free_memory(args);
				print_error();
			}
			j++;
		}
		free_memory(args);
		i++;
	}
}

void	input_storage(t_list **stk_a, char **argv)
{
	int		i;
	int		j;
	char	**args;
	t_list	*newnode;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			newnode = ft_lstnew(convert_string(args[j]));
			if (!newnode)
			{
				free_memory(args);
				print_error();
			}
			ft_lstadd_back(stk_a, newnode);
			j++;
		}
		i++;
		free_memory(args);
	}
}

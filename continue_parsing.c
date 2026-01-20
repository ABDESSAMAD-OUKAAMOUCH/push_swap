/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:48:48 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/19 14:41:42 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_all_args(char **str, int j, char **arg)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (convert_string(arg[j]) == convert_string(str[k]))
			return (0);
		k++;
	}
	return (1);
}

int	check_one_arg(int j, char **arg)
{
	int	k;

	k = j + 1;
	while (arg[k])
	{
		if (convert_string(arg[j]) == convert_string(arg[k]))
			return (0);
		k++;
	}
	return (1);
}

int	check_is_duplicate(int argc, int i, char **argv, char **arg)
{
	int		h;
	char	**str;
	int		j;
	int		k;

	h = i + 1;
	while (h < argc)
	{
		str = ft_split(argv[h], ' ');
		j = 0;
		while (arg[j])
		{
			if (!check_all_args(str, j, arg))
			{
				free_memory(arg);
				free_memory(str);
				return (0);
			}
			j++;
		}
		free_memory(str);
		h++;
	}
	return (1);
}

int	is_unique(char **argv, int argc)
{
	int		j;
	int		k;
	int		i;
	char	**arg;

	i = 1;
	while (i < argc)
	{
		arg = ft_split(argv[i], ' ');
		j = 0;
		while (arg[j])
		{
			if (!check_one_arg(j, arg))
			{
				free_memory(arg);
				return (0);
			}
			j++;
		}
		if (!check_is_duplicate(argc, i, argv, arg))
			return (0);
		free_memory(arg);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:31:48 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/19 13:40:49 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	remove_space(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

int	check_int_scope(char *str, int i, int sign)
{
	unsigned long	res;

	res = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res > INT_MAX)
			return (0);
		if (sign == -1 && res > (unsigned long)INT_MAX + 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(char *str)
{
	int				i;
	int				sign;

	if (str == NULL)
		return (0);
	i = remove_space(str);
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!str[i])
		return (0);
	return (check_int_scope(str, i, sign));
}

int	convert_string(char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	if (str == NULL)
		return (0);
	i = remove_space(str);
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:14:40 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/20 12:23:25 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}

t_list	*ft_lstnew(int nbr)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->number = nbr;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = begin_list;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

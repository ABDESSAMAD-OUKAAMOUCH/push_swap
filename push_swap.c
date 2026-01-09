#include <stdio.h>
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
t_list	*ft_lstnew(int  nbr)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->number = nbr;
	node->next = NULL;
    node->prev = NULL;
	return (node);
}
void    input_storage(t_list **stk_a, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        t_list *newnode = ft_lstnew(convert_string(argv[i]));
        if (!newnode)
            print_error();
        ft_lstadd_back(stk_a, newnode);
        i++;
    }
}

int main(int argc, char **argv)
{
    t_list  *stk_a;
    t_list  *stk_b;
    int i;
    if (argc == 1)
        return (0);
    stk_a = NULL;
    stk_b = NULL;
    i = 1;
    while (argv[i])
    {
        if (!is_number(argv[i]) || !is_unique_scope(argv))
        {
            write(2, "Error\n",6);
            return (0);
        }
        i++;
    }
    input_storage(&stk_a, argv);
    t_list *tmp = stk_a;
    while (tmp)
    {
        printf("%d\n",tmp->number);
        tmp = tmp->next;
    }
    reverse_helper(&stk_a);
    while (stk_a)
    {
        printf("%d\n",stk_a->number);
        stk_a = stk_a->next;
    }
    return 0;
}

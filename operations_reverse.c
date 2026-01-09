#include "push_swap.h"

void    reverse_helper(t_list **lst)
{
    t_list  *last_p;
    t_list  *first_p;
    last_p = *lst;
    first_p = *lst;
    while (last_p->next != NULL)
        last_p =  last_p->next;
    last_p->prev->next = NULL;
    last_p->prev = NULL;
    last_p->next = first_p;
    first_p->prev =   last_p;
    *lst =  last_p;
    
}

void    rra(t_list **lst)
{
    if (!lst || !*lst || !(*lst)->next)
        return ;
    reverse_helper(lst);
    write(1,"rra\n",4);
}

void    rrb(t_list **lst)
{
    if (!lst || !*lst || !(*lst)->next)
        return ;
    reverse_helper(lst);
    write(1,"rrb\n",4);
}

void    rrr(t_list **stk_a, t_list **stk_b)
{
    if (!stk_a || !*stk_a || !(*stk_a)->next || !stk_b || !*stk_b || !(*stk_b)->next)
        return ;
    reverse_helper(stk_a);
    reverse_helper(stk_b);
    write(1,"rrr\n",4);
}
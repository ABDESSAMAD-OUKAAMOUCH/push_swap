#include "push_swap.h"

void    rotate_helper(t_list **lst)
{
    t_list *p1;
    t_list *last_p;
    
    p1 = *lst;
    last_p = *lst;
    while (last_p->next != NULL)
        last_p = last_p->next;
    *lst = p1->next;
    (*lst)->prev = NULL;
    p1->prev = last_p;
    last_p->next = p1;
    p1->next = NULL;
}

void    ra(t_list **lst)
{
    if (!lst || !*lst || !(*lst)->next)
        return ;
    rotate_helper(lst);
    write(1,"ra\n",3);
}

void    rb(t_list **lst)
{
    if (!lst || !*lst || !(*lst)->next)
        return ;
    rotate_helper(lst);
    write(1,"rb\n",3);
}

void    rr(t_list **stk_a, t_list **stk_b)
{
    if (!stk_a || !*stk_a || !(*stk_a)->next || !stk_b || !*stk_b || !(*stk_b)->next)
        return ;
    rotate_helper(stk_a);
    rotate_helper(stk_b);
    write(1,"rr\n",3);
}
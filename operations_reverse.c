#include "push_swap.h"

void    reverse_helper(t_list **lst)
{
    t_list *tmp;
    t_list *next;
    t_list *prev;
    
    tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    *lst = tmp;
    while (tmp != NULL){
        prev = tmp->prev;
        next = tmp->next;
        tmp->next = prev;
        tmp->prev = next;
        tmp = prev;
    }
}

void    rra(t_list **lst)
{
    if (!lst || !*lst || !(*lst)->next)
        return ;
    reverse_helper(lst);
    write(1,"rra\n",3);
}

void    rrb(t_list **lst)
{
    if (!lst || !*lst || !(*lst)->next)
        return ;
    reverse_helper(lst);
    write(1,"rrb\n",3);
}

void    rrr(t_list **stk_a, t_list **stk_b)
{
    if (!stk_a || !*stk_a || !(*stk_a)->next || !stk_b || !*stk_b || !(*stk_b)->next)
        return ;
    reverse_helper(stk_a);
    reverse_helper(stk_b);
    write(1,"rrr\n",3);
}
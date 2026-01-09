#include "push_swap.h"

void    pa(t_list **stk_a, t_list **stk_b)
{
    if (!stk_a || !*stk_a || !stk_b || !*stk_b)
        return ;
    t_list *tmp = stk_a;
    *stk_a = *stk_b;
    (*stk_a)->next = stk_a;
    (*stk_b) = (*stk_b)->next;
}
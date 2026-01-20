#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_list
{
    int number;
    int index;
    struct s_list *next;
    struct s_list *prev;
} t_list;

int is_unique(char **argv, int argc);
int is_number(char *str);
int convert_string(char *str);
int check_overflow(char *str);
void    print_error();
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int  nbr);
char	**ft_split(char const *s, char c);
void    free_memory(char **args);
void    pa(t_list **stk_a, t_list **stk_b);
void    pb(t_list **stk_a, t_list **stk_b);
void    ra(t_list **lst);
void    rb(t_list **lst);
void    rrb(t_list **lst);
void    rra(t_list **lst);
void    sa(t_list **lst);
void    sb(t_list **lst);
void    rr(t_list **stk_a, t_list **stk_b);
#endif
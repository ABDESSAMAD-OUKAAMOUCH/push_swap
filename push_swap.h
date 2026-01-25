/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:08:06 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/23 11:08:12 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int is_unique(char **argv, int argc);
int convert_string(char *str);
int check_overflow(char *str);
int pos_index(t_list *stk_a ,int max);
void    print_error();
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int  nbr);
int	ft_list_size(t_list *begin_list);
char	**ft_split(char const *s, char c);
void    free_memory(char **args);
void free_stack(t_list **stk);
int check_is_sort(t_list *stk_a);
void    input_storage(t_list **stk_a, char **argv);
void is_valid_arg(char **argv);
void sort_two_items(t_list **stk_a);
void sort_three_items(t_list **stk_a);
void sort_for_five_items(t_list **stk_a, t_list **stk_b);
void	push_to_a(t_list **stk_a, t_list **stk_b);
void	puch_to_b(t_list **stk_a, t_list **stk_b, int chunksize);
void	sort_stack(t_list **stk_a, t_list **stk_b);
void	check_op(t_list **stk_a, t_list **stk_b, char *line);
void    pa(t_list **stk_a, t_list **stk_b, int is_pr);
void    pb(t_list **stk_a, t_list **stk_b, int is_pr);
void    sa(t_list **lst, int is_pr);
void    sb(t_list **lst, int is_pr);
void	ss(t_list **stk_a, t_list **stk_b, int is_pr);
void    ra(t_list **lst, int is_pr);
void    rb(t_list **lst, int is_pr);
void    rr(t_list **stk_a, t_list **stk_b, int is_pr);
void    rra(t_list **lst, int is_pr);
void    rrb(t_list **lst, int is_pr);
void	rrr(t_list **stk_a, t_list **stk_b, int is_pr);

#endif

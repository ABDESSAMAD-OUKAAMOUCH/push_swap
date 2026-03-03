/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:04:22 by aoukaamo          #+#    #+#             */
/*   Updated: 2026/01/26 11:04:46 by aoukaamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	pa(t_list **stk_a, t_list **stk_b);
void	pb(t_list **stk_a, t_list **stk_b);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **stk_a, t_list **stk_b);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **stk_a, t_list **stk_b);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **stk_a, t_list **stk_b);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		is_unique(char **argv, int argc);
int		convert_string(char *str);
int		is_overflow(char *str);
void	print_error(void);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int nbr);
int		ft_list_size(t_list *begin_list);
char	**ft_split(char const *s, char c);
void	free_memory(char **args);
void	free_stack(t_list **stk);
int		check_is_sort(t_list *stk_a);
void	input_storage(t_list **stk_a, char **argv);
void	is_valid_arg(char **argv);
void	check_op(t_list **stk_a, t_list **stk_b, char *line);

#endif

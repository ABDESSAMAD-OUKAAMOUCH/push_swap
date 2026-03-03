# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoukaamo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/03 13:38:26 by aoukaamo          #+#    #+#              #
#    Updated: 2026/02/03 13:38:38 by aoukaamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c \
	parsing.c \
	continue_parsing.c \
	finish_parsing.c \
	linkedlist_operations.c \
	push_operations.c \
	reverse_operations.c \
	rotate_operations.c \
	swap_operations.c \
	sort_five.c \
	sort_stack_utils1.c \
	sort_stack_utils2.c \
	utils1.c \
	utils2.c
BONUS = checker_bonus.c \
	checker_utils_bonus.c \
	parsing_bonus.c \
	continue_parsing_bonus.c \
	finish_parsing_bonus.c \
	get_operation_bonus.c \
	get_operation_utils_bonus.c \
	linkedlist_operations_bonus.c \
	push_operations_bonus.c \
	reverse_operations_bonus.c \
	rotate_operations_bonus.c \
	swap_operations_bonus.c \
	utils1_bonus.c \
	utils2_bonus.c

OBJ_SRC = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAGS)  $(OBJ_SRC) -o $(NAME)
bonus : $(BONUS_NAME)
$(BONUS_NAME) : $(OBJ_BONUS)
	$(CC) $(CFLAGS)  $(OBJ_BONUS) -o $(BONUS_NAME)
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
%_bonus.o : %_bonus.c push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ_SRC) $(OBJ_BONUS)
fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
re : fclean all

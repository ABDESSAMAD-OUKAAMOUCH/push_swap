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
BONUS =  checker.c \
	checker_utils.c \
	parsing.c \
	continue_parsing.c \
	finish_parsing.c \
	linkedlist_operations.c \
	push_operations.c \
	reverse_operations.c \
	rotate_operations.c \
	swap_operations.c \
	get_next_line.c \
	get_next_line_utils.c \
	utils1.c \
	utils2.c
OBJ_SRC = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAGS)  $(OBJ_SRC) -o $(NAME)
bonus : $(OBJ_BONUS)
	$(CC) $(CFLAGS)  $(OBJ_BONUS) -o $(BONUS_NAME)
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ_SRC) $(OBJ_BONUS)
fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
re : fclean all
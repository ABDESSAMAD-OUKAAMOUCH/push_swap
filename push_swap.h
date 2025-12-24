#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_list
{
    int number;
    struct s_list *next;
    struct s_list *prev;
} t_list;

int is_unique_scope(char **argv);
int is_number(char *str);
int convert_string(char *str);
void    print_error();
#endif
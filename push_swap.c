#include <stdio.h>
#include "push_swap.h"

void    input_storage(t_list **stk_a, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        t_list *newnode = ft_lstnew(convert_string(argv[i]));
        if (!newnode)
            print_error();
        ft_lstadd_back(stk_a, newnode);
        i++;
    }
}
int cmp(int a, int b){
    return (a - b);
}

void sort(int *arr, int size, t_list *stk_a){
    int i = 1;
    int current;
    int j;
    while (i < size)
    {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && current < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
        i++;
    }
    j = 0;
    t_list *lst = stk_a;
    while (stk_a && j < size)
    {
        if(stk_a->number == arr[j]){
            stk_a->index = j;
            j++;
            stk_a = lst;
        }else{
            stk_a = stk_a->next;
        }
    }
}

int main(int argc, char **argv)
{
    t_list  *stk_a;
    t_list  *stk_b;
    int i;
    if (argc == 1)
        return (0);
    stk_a = NULL;
    stk_b = NULL;
    i = 1;
    while (argv[i])
    {
        if (!is_number(argv[i]) || !is_unique_scope(argv))
        {
            write(2, "Error\n",6);
            return (0);
        }
        i++;
    }
    input_storage(&stk_a, argv);
    int counter = 0;
    t_list *tmp = stk_a;
    while (tmp)
    {
        tmp = tmp->next;
        counter++;
    }
    tmp = stk_a;
    int arr[counter];
    i = 0;
    while (tmp)
    {
        arr[i] = tmp->number;
        tmp = tmp->next;
        i++;
    }
    sort(arr,counter,stk_a);
    while (stk_a)
    {
        if (stk_a->index >= 0 && stk_a->index <= 10){
            pb(&stk_a, &stk_b);
        }else{
            ra(&stk_a);
        }
    }
    tmp = stk_b;
    // while (tmp)
    // {
    //     printf("%d\n",tmp->number);
    //     tmp = tmp->next;
    // }
    tmp = stk_b;
    int max = stk_b->index;
    while (stk_b)
    {
        printf("index = %d number = %d\n",stk_b->index,stk_b->number);
        if (stk_b->index > max)
        {
            max = stk_b->index;
            printf("%d",max);
        }
        stk_b = stk_b->next;
    }
    printf("%d",max);
    // i = 0;
    // while (i < counter)
    // {
    //     printf("%d\n",arr[i]);
    //     i++;
    // }
    
    // i = 0;
    // while (i < counter)
    // {
    //     printf("%d\n",arr[i]);
    //     i++;
    // }
    return 0;
}

#include <stdio.h>
#include "push_swap.h"
 
int max_index(t_list *stk_a)
{
    t_list *max;
    t_list *tmp;

    tmp = stk_a;
    while (tmp)
    {
        if (tmp->index > max->index)
        {
            max = tmp;
        }
        tmp = tmp->next;
    }
    return (max->index);
}

int pos_index(t_list *stk_a ,int max){
    t_list *tmp;
    int i;
    tmp = stk_a;
    i = 0;

    while (tmp)
    {
        if (tmp->index == max)
            return (i);
        tmp = tmp->next;
        i++;
    }
    return (-1);
}
int	ft_list_size(t_list *begin_list)
{
    int size = 0;
    t_list *tmp = begin_list;
    while (tmp)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}
void free_memory(char **args){
    int j;

    j = 0;
    while (args[j])
        free(args[j++]);
    free(args);
}

void    input_storage(t_list **stk_a, char **argv)
{
    int i = 1;
    int j;
    char **args;

    while (argv[i])
    {
        args = ft_split(argv[i],' ');
        j = 0;
        while (args[j])
        {
             t_list *newnode = ft_lstnew(convert_string(args[j]));
            if (!newnode){
                free_memory(args);
                print_error();
            }
            ft_lstadd_back(stk_a, newnode);
            j++;
        }
        i++;
        free_memory(args);
    }
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


void sort_list(t_list **stk_a, t_list **stk_b, int counter){
    t_list *tmp;
    t_list *max;
    int i;
    int pos;

    while (stk_b)
    {    
        tmp = *stk_b;
        max = *stk_b;
        i = 0;
        pos = 0;
        while (tmp)
        {
            if (tmp->index > max->index)
            {
                max = tmp;
                pos = i;
            }
            tmp = tmp->next;
            i++;
        }
        if (max->prev == NULL){
            pa(stk_a, stk_b);
            counter--;
        }else if (pos <= counter / 2){
            rb(stk_b);
        }else{
            rrb(stk_b);
        }
    }
}
void sort_two_items(t_list **stk_a){
    if((*stk_a)->index > (*stk_a)->next->index)
        sa(stk_a);
}
void sort_three_items(t_list **stk_a){
            if((*stk_a)->next->index > (*stk_a)->next->next->index)
                ra(stk_a);
            if((*stk_a)->next->index > (*stk_a)->next->next->index)
                ra(stk_a);
            if((*stk_a)->index > (*stk_a)->next->index)
                sa(stk_a);
            if((*stk_a)->next->index > (*stk_a)->next->next->index)
                rra(stk_a);
            if((*stk_a)->index > (*stk_a)->next->index)
                sa(stk_a);
}
void sort_for_five_items(t_list **stk_a, t_list **stk_b, int counter)
{
    int push0;
    int push1;

    push0 = 0;
    push1 = 0;
    while (*stk_a)
    {
        if ((*stk_a)->index == 0){
            pb(stk_a, stk_b);
            push0 = 1;
        }if((*stk_a)->index == 1){
            pb(stk_a, stk_b);
            push1 = 1;
        }
        if (push0 && push1)
            break;
        else
            ra(stk_a);
    }
    if (counter == 4 || counter == 9)
        sort_two_items(stk_a);
    else
        sort_three_items(stk_a);
    pa(stk_a,stk_b);
    pa(stk_a,stk_b);
    sort_two_items(stk_a);
}
void sort_for_five_items_10(t_list **stk_a, t_list **stk_b, int counter)
{
    int push0;
    int push1;

    push0 = 0;
    push1 = 0;
    while (*stk_a)
    {
        if ((*stk_a)->index == 5){
            pb(stk_a, stk_b);
            push0 = 1;
        }if((*stk_a)->index == 6){
            pb(stk_a, stk_b);
            push1 = 1;
        }
        if (push0 && push1)
            break;
        else
            ra(stk_a);
    }
    if (counter == 9)
        sort_two_items(stk_a);
    else
        sort_three_items(stk_a);
    pa(stk_a,stk_b);
    pa(stk_a,stk_b);
    sort_two_items(stk_a);
}

int check_is_sort(t_list *stk_a)
{
    while (stk_a && stk_a->next)
    {
            if(stk_a->number > stk_a->next->number)
                return (0);
            stk_a = stk_a->next;
    }
    return (1);
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
    int j;
    int k;
    char **args;
    while (argv[i])
    {
        j = 0;
        args = ft_split(argv[i],' ');
        if (!args || !args[0]){
            free_memory(args);
            print_error();
        }
        while (args[j])
        {
            if (!check_overflow(args[j]))
            {
                write(2, "Error\n",6);
                free_memory(args);
                return (0);
            }
            j++;
        }
        free_memory(args);
        i++;
    }
    if (!is_unique(argv, argc))
        print_error();
    input_storage(&stk_a, argv);
    if (check_is_sort(stk_a))
        return (0);
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
    tmp = stk_a;
    // while (tmp)
    // {
    //     printf("nb %d ",tmp->number);
    //     printf("in %d\n",tmp->index);
    //     tmp = tmp->next;
    // }
    int chunksize;
    int current_chunk;
    if (counter <= 10){
        if (counter == 2){
            sort_two_items(&stk_a);
        }else if(counter == 3){
            sort_three_items(&stk_a);
        }
        else if (counter == 4 || counter == 5)
        {
            sort_for_five_items(&stk_a, &stk_b,counter);
        }else{
            i = 0;
            while (i < 5)
            {

                if (stk_a->index >= 0 && stk_a->index <= 4)
                {
                    pb(&stk_a, &stk_b);
                    i++;
                }
                else{
                    ra(&stk_a);
                }
            }
            if (counter == 6)
                pb(&stk_a, &stk_b);
            else if (counter == 7)
                sort_two_items(&stk_a);
            else if (counter == 8)
                sort_three_items(&stk_a);
            else
                sort_for_five_items_10(&stk_a, &stk_b, counter);
            t_list *max ;
            i = 0;
            int pos = 0;
            while (stk_b)
            {    
                tmp = stk_b;
                max = stk_b;
                i = 0;
                pos = 0;
                while (tmp)
                {
                    if (tmp->index > max->index)
                    {
                        max = tmp;
                        pos = i;
                    }
                    tmp = tmp->next;
                    i++;
                }
                if (max->prev == NULL){
                    pa(&stk_a, &stk_b);
                    counter--;
                }else if (pos <= counter / 2){
                    rb(&stk_b);
                }else if(pos > counter / 2){
                    rrb(&stk_b);
                }
            }
        }
    }else{
        if (counter <= 100){
            chunksize = 20;
            current_chunk = 0;
        }else{
            chunksize = 68;
            current_chunk = 0;
        }
        int pushed = 0;
        while (stk_a)
        {
            int min_index;
            int tmp;
            int max_index;
            int middle_index;
            min_index = current_chunk * chunksize;
            max_index = min_index + chunksize - 1;
            middle_index = (max_index + min_index) / 2;
            if (ft_list_size(stk_a) == 1){
                pb(&stk_a, &stk_b);
                break;
            }
            if (stk_a->index >= min_index && stk_a->index <= max_index){
                tmp = stk_a->index;
                pb(&stk_a, &stk_b);
                if (tmp < middle_index)
                    rb(&stk_b);
                pushed++;
                if (pushed == chunksize)
                {
                    current_chunk++;
                    pushed = 0;
                }
            }else{
                ra(&stk_a);
            }
        }
        
        int max;
        int pos_max = 0;
        int pos_next = 0;
        int next_m;
        while (stk_b)
        {
            max = max_index(stk_b);
            pos_max = pos_index(stk_b, max);
            pos_next = pos_index(stk_b, max - 1);
            counter = ft_list_size(stk_b);
            int c_m = pos_max;
            int c_n = pos_next;
            if (pos_max > counter / 2)
                c_m = counter - pos_max;
            if (pos_next > counter / 2)
                c_n = counter - pos_next;
            if (pos_next != -1 && c_m > c_n){
                while (stk_b->index != max - 1)
                {
                    pos_next = pos_index(stk_b, max - 1);
                    if (pos_next <= counter / 2)
                        rb(&stk_b);
                    else
                        rrb(&stk_b);
                }
                pa(&stk_a, &stk_b);
                counter = ft_list_size(stk_b);
                pos_max = pos_index(stk_b, max);
                while (stk_b->index != max)
                {
                    pos_max = pos_index(stk_b, max);
                    if (pos_max <= counter / 2)
                        rb(&stk_b);
                    else
                        rrb(&stk_b);
                }
                pa(&stk_a, &stk_b);
                sa(&stk_a);
            }
            else{
                while (stk_b->index != max)
                {
                    pos_max = pos_index(stk_b, max);
                    if (pos_max <= counter / 2)
                        rb(&stk_b);
                    else
                        rrb(&stk_b);
                }
                pa(&stk_a, &stk_b);
            }
        }
    }
    // tmp = stk_a;
    // while (tmp)
    // {
    //     printf("nn%d\n",tmp->number);
    //     tmp = tmp->next;
    // }
    return 0;
}

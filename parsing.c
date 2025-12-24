#include "push_swap.h"

static int	remove_space(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

void    print_error()
{
    write(2, "Error\n",6);
    exit(1);
}
int convert_string(char *str)
{
	int					i;
	unsigned long   res;
	int					sign;

	if (str == NULL)
		return (0);
	i = remove_space(str);
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res > INT_MAX)
			print_error();
		if (sign == -1 && res > (unsigned long)INT_MAX + 1)
			print_error();
		i++;
	}
	return ((int)(res * sign));
}

int is_number(char *str)
{
    int i = 0;
    if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int is_unique_scope(char **argv)
{
    int i = 1;
    while (argv[i])
    {
        
        int j = i + 1;
        while (argv[j] != NULL)
        {
            if (convert_string(argv[i]) == convert_string(argv[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
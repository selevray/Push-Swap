#include "push_swap.h"

int	has_duplicate(t_node *pile, int value, int size)
{
	int		i;
	t_node	*current;

	if (pile == NULL)
		return (0);
	current = pile;
	i = 0;
	while (i < size)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i
			+ 1] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	int i = 0;
	int sign = 1;
	long result = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void print_stack(t_node *pile, char *name, int size)
{
    if (!pile)
    {
        ft_printf("%s: (vide)\n", name);
        return;
    }
    
    ft_printf("%s: ", name);
    t_node *current = pile;
    int i = 0;
    while (i < size)
    {
        ft_printf("%d ", current->value);
        current = current->next;
        i++;
    }
    ft_printf("\n");
}
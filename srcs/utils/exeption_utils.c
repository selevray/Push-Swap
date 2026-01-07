#include "push_swap.h"

int	find_min(t_node *pile, int size)
{
	int	min;
	int	i;

	min = pile->value;
	i = 0;
	while (i < size)
	{
		if (pile->value < min)
			min = pile->value;
		pile = pile->next;
		i++;
	}
	return (min);
}

int	find_position(t_node *pile, int value, int size)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (i < size)
	{
		if (pile->value == value)
			return (i);
		pile = pile->next;
		i++;
	}
	return (pos);
}

void	bring_to_top(t_data *piles, int value)
{
	int	size_a;
	int	pos;

	size_a = piles->size_a;
	pos = find_position(piles->pile_a, value, size_a);
	if (pos < size_a / 2)
	{
		while (piles->pile_a->value != value)
			ra(piles);
	}
	else
	{
		while (piles->pile_a->value != value)
			rra(piles);
	}
}

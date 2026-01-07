#include "push_swap.h"

void	sort_two(t_data *piles)
{
	if (piles->pile_a->value > piles->pile_a->next->value)
		sa(piles);
}

void	sort_three(t_data *piles)
{
	int	a;
	int	b;
	int	c;

	a = piles->pile_a->value;
	b = piles->pile_a->next->value;
	c = piles->pile_a->next->next->value;
	if (a > b && a > c && b > c)
		sa(piles), rra(piles);
	else if (a > b && a > c)
		ra(piles);
	else if (b > a && b > c && a > c)
		rra(piles);
	else if (b > a && b > c)
		sa(piles), ra(piles);
	else if (a > b)
		sa(piles);
}

void	sort_five(t_data *piles)
{
	int	min;

	min = find_min(piles->pile_a, piles->size_a);
	bring_to_top(piles, min);
	pb(piles);

    min = find_min(piles->pile_a, piles->size_a);
    bring_to_top(piles, min);
    pb(piles);

    sort_three(piles);
    pa(piles);
    pa(piles);
}

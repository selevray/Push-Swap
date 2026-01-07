#include "push_swap.h"
#include <stdio.h>

// void	bubblesort(int *tab, int len)
// {
// 	int	i;
// 	int	temp;
//     int swap = 1;
// 	while (swap)
// 	{
// 		i = 1;
//         swap = 0;
// 		while (i < len)
// 		{
// 			if (tab[i - 1] > tab[i])
// 			{
// 				temp = tab[i];
// 				tab[i] = tab[i - 1];
// 				tab[i - 1] = temp;
//                 swap = 1;
// 			}
// 			i++;
// 		}
// 	}
// }

void	bubblesort(t_data *piles)
{
	int		swap;
	int		i;

	swap = 1;
	while (swap)
	{
		i = 0;
		swap = 0;
		while (i < piles->size_a)
		{
			if (piles->pile_a->value > piles->pile_a->next->value && i < piles->size_a - 1)
			{
				sa(piles);
				swap = 1;
			}
			i++;
			ra(piles);
		}
	}
}

// int	main(void)
// {
// 	int		tab[] = {3, 5, 1, 7, 2, 9, 18, 4};
// 	int		size;
// 	t_data	piles;
// 	t_node	*node;
// 	int		i;

// 	i = 0;
// 	size = sizeof(tab) / sizeof(*tab);
// 	piles.pile_a = NULL;
// 	piles.pile_b = NULL;
// 	piles.size_a = 0;
// 	piles.size_b = 0;
// 	while (i < size)
// 	{
// 		node = new_node(tab[i]);
// 		add_top(&piles.pile_a, node);
// 		piles.size_a++;
// 		i++;
// 	}
// 	print_stack(piles.pile_a, "Pile A", piles.size_a);
// 	print_stack(piles.pile_b, "Pile B", piles.size_b);
// 	bubblesort(&piles);
// 	print_stack(piles.pile_a, "Pile A", piles.size_a);
// 	print_stack(piles.pile_b, "Pile B", piles.size_b);
// 	return (0);
// }

#include "push_swap.h"

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
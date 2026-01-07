#include "push_swap.h"

void	bubble_sort_array(int *tab, int size)
{
	int	i;
	int	temp;
	int	swap;

	swap = 1;
	while (swap)
	{
		i = 1;
		swap = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
				swap = 1;
			}
			i++;
		}
	}
}

int	*copy_stack_to_array(t_node *pile, int size)
{
	int		*tab;
	t_node	*current;
	int		i;

	if (pile == NULL || size == 0)
		return (NULL);
	tab = malloc(size * sizeof(int));
	if (tab == NULL)
		return (NULL);
	current = pile;
	i = 0;
	while (i < size)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	return (tab);
}

int	find_index(int *tab, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
void	index_stack(t_node *pile, int size)
{
	t_node	*current;
	int		i;
	int		index;
	int		*tab;

	i = 0;
	index = 0;
	tab = copy_stack_to_array(pile, size);
	bubble_sort_array(tab, size);
	current = pile;
	i = 0;
	while (i < size)
	{
		index = find_index(tab, size, current->value);
		current->value = index;
		current = current->next;
		i++;
	}
	free(tab);
}

int	get_max_bits(int size)
{
	int	bits;
	int	max_value;

	bits = 0;
	max_value = size - 1;
	while (max_value > 0)
	{
		max_value = max_value >> 1;
		bits++;
	}
	return (bits);
}

int	get_bit(int num, int bit_position)
{
	return ((num >> bit_position) & 1);
}

void radix_sort(t_data *piles)
{
    int max_bits;
    int bit;
    int size_a;
    int i;

    max_bits = get_max_bits(piles->size_a);
    bit = 0;
    
    while (bit < max_bits)
    {
        size_a = piles->size_a;
        i = 0;
        
        while (i < size_a)
        {
            if (get_bit(piles->pile_a->value, bit) == 0)
                pb(piles);
            else
                ra(piles);
            i++;
        }
        
		while (piles->size_b > 0)
            pa(piles);
        
        bit++;
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

// int	main(void)
// {
// 	ft_printf("\n=== TEST get_bit ===\n");
// 	ft_printf("5 (binaire:  101)\n");
// 	ft_printf("  bit 0: %d\n", get_bit(5, 0)); // 1
// 	ft_printf("  bit 1: %d\n", get_bit(5, 1)); // 0
// 	ft_printf("  bit 2: %d\n", get_bit(5, 2)); // 1

// 	ft_printf("\n6 (binaire: 110)\n");
// 	ft_printf("  bit 0: %d\n", get_bit(6, 0)); // 0
// 	ft_printf("  bit 1: %d\n", get_bit(6, 1)); // 1
// 	ft_printf("  bit 2: %d\n", get_bit(6, 2)); // 1

// 	ft_printf("\n7 (binaire: 111)\n");
// 	ft_printf("  bit 0: %d\n", get_bit(7, 0)); // 1
// 	ft_printf("  bit 1: %d\n", get_bit(7, 1)); // 1
// 	ft_printf("  bit 2: %d\n", get_bit(7, 2)); // 1

// ft_printf("\n=== TEST get_max_bits ===\n");
// ft_printf("size = 3 (max = 2) → %d bits\n", get_max_bits(3));       // 2
// ft_printf("size = 5 (max = 4) → %d bits\n", get_max_bits(5));       // 3
// ft_printf("size = 8 (max = 7) → %d bits\n", get_max_bits(8));       // 3
// ft_printf("size = 100 (max = 99) → %d bits\n", get_max_bits(100));  // 7
// ft_printf("size = 500 (max = 499) → %d bits\n", get_max_bits(500)); // 9
// }

// int main(void)
// {
//     int tab[] = {3, 5, 1, 7, 2, 9, 18, 4};
//     int size;
//     t_data piles;
//     t_node *node;
//     int i;

//     i = 0;
//     size = sizeof(tab) / sizeof(*tab);
//     piles.pile_a = NULL;
//     piles.pile_b = NULL;
//     piles.size_a = 0;
//     piles.size_b = 0;

// 	while (i < size)
//     {
//         node = new_node(tab[i]);
//         add_top(&piles. pile_a, node);
//         piles.size_a++;
//         i++;
//     }

//     ft_printf("=== PILE ORIGINALE ===\n");
//     print_stack(piles. pile_a, "Pile A", piles.size_a);

//     index_stack(piles.pile_a, piles.size_a);

//     ft_printf("\n=== PILE INDEXÉE ===\n");
//     print_stack(piles.pile_a, "Pile A", piles.size_a);

//     radix_sort(&piles);

//     ft_printf("\n=== PILE TRIÉE ===\n");
//     print_stack(piles.pile_a, "Pile A", piles.size_a);
//     print_stack(piles.pile_b, "Pile B", piles.size_b);

//     return (0);
// }
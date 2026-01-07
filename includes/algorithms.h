#ifndef ALGORITHMS_H
# define ALGORITHMS_H

typedef struct s_node	t_node;
typedef struct s_data	t_data;

void	bubblesort(t_data *piles);
void	radix_sort(t_data *piles);
void	sort_two(t_data *piles);
void	sort_three(t_data *piles);
void	sort_five(t_data *piles);

void	bubble_sort_array(int *tab, int size);
int		*copy_stack_to_array(t_node *pile, int size);
int		find_index(int *tab, int size, int value);
void	index_stack(t_node *pile, int size);
int		get_max_bits(int size);
int		get_bit(int num, int bit_position);

#endif

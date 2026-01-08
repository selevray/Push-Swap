#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_printf("DEBUG: argc = %d\n", argc);
	data.pile_a = NULL;
	data.pile_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	data.ops_count = 0;
	ft_printf("DEBUG: Avant parse_arguments\n");
	if (parse_arguments(argc, argv, &data) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_printf("DEBUG:  Parsing OK !  size_a = %d\n", data.size_a);
	if (data.size_a == 2)
		sort_two(&data);
	else if (data.size_a == 3)
		sort_three(&data);
	else if (data.size_a <= 5)
		sort_five(&data);
	else
	{
		radix_sort(&data);
		index_stack(data.pile_a, data.size_a);
	}
	free_stack(data.pile_a, data.size_a);
	free_stack(data.pile_b, data.size_b);
	ft_printf("%d", data.ops_count);
	return (0);
}

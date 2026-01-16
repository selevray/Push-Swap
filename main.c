/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:35:08 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 23:27:39 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_sort(t_data *data)
{
	int median;

	if (data->size_a == 0)
		return ;
	if (is_sorted(data))
		return ;
	if (data->size_a == 2)
		sort_two(data);
	else if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a <= 5)
		sort_five(data);
	else
	{
		index_stack(data->pile_a, data->size_a, &median);
		insertion_sort(data, median);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.pile_a = NULL;
	data.pile_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	data.ops_count = 0;
	if (parse_arguments(argc, argv, &data) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	execute_sort(&data);
	free_stack(data.pile_a, data.size_a);
	free_stack(data.pile_b, data.size_b);
	return (0);
}

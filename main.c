/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:35:08 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 12:04:49 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_data *data)
{
	t_node	*current;
	int		i;

	if (data->pile_a == NULL || data->size_a <= 1)
		return (1);
	if (data->pile_b != NULL || data->size_b > 0)
		return (0);
	current = data->pile_a;
	i = 0;
	while (i < data->size_a - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

static void	execute_sort(t_data *data)
{
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
	else if (data->size_a <= 100)
	{
		index_stack(data->pile_a, data->size_a);
		insertion_sort(data);
	}
	else
	{
		index_stack(data->pile_a, data->size_a);
		radix_sort(data);
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

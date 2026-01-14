/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:27:04 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 17:23:35 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.pile_a = NULL;
	data.pile_b = NULL;
	data.size_a = 0;
	data.size_b = 0;
	if (parse_arguments(argc, argv, &data) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (read_and_execute(&data) == 0)
	{
		write(2, "Error\n", 6);
		free_stack(data.pile_a, data.size_a);
		free_stack(data.pile_b, data.size_b);
		return (1);
	}
	if (is_sorted(&data) && data.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(data.pile_a, data.size_a);
	free_stack(data.pile_b, data.size_b);
	return (0);
}

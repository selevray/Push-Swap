/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:22 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/16 14:27:31 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (data->size_a < 2)
		return ;
	swap(&data->pile_a);
	write(1, "sa\n", 3);
}

void	ra(t_data *data)
{
	if (data->size_a < 2)
		return ;
	reverse(&data->pile_a);
	write(1, "ra\n", 3);
}

void	rra(t_data *data)
{
	if (data->size_a < 2)
		return ;
	reverse_rotate(&data->pile_a, data->size_a);
	write(1, "rra\n", 4);
}

void	pa(t_data *data)
{
	push(&data->pile_b, &data->pile_a, &data->size_b, &data->size_a);
	write(1, "pa\n", 3);
}

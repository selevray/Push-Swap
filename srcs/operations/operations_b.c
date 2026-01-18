/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:30 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/16 14:27:39 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_data *data)
{
	if (data->size_b < 2)
		return ;
	swap(&data->pile_b);
	write(1, "sb\n", 3);
}

void	rb(t_data *data)
{
	if (data->size_b < 2)
		return ;
	reverse(&data->pile_b);
	write(1, "rb\n", 3);
}

void	rrb(t_data *data)
{
	if (data->size_b < 2)
		return ;
	reverse_rotate(&data->pile_b, data->size_b);
	write(1, "rrb\n", 4);
}

void	pb(t_data *data)
{
	push(&data->pile_a, &data->pile_b, &data->size_a, &data->size_b);
	write(1, "pb\n", 3);
}

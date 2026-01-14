/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:22 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 11:44:23 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	if (data->size_a < 2)
		return ;
	swap(&data->pile_a);
	data->ops_count++;
	write(1, "sa\n", 3);
}

void	ra(t_data *data)
{
	if (data->size_a < 2)
		return ;
	data->pile_a = data->pile_a->next;
	data->ops_count++;
	write(1, "ra\n", 3);
}

void	rra(t_data *data)
{
	t_node	*last;

	if (data->size_a < 2)
		return ;
	last = find_last(data->pile_a);
	data->pile_a = last;
	data->ops_count++;
	write(1, "rra\n", 4);
}

void	pa(t_data *data)
{
	t_node	*move;
	t_node	*last_b;

	if (data->pile_b == NULL)
		return ;
	move = data->pile_b;
	if (data->size_b == 1)
		data->pile_b = NULL;
	else
	{
		last_b = find_last(data->pile_b);
		data->pile_b = data->pile_b->next;
		last_b->next = data->pile_b;
	}
	data->size_b--;
	move->next = move;
	add_top(&data->pile_a, move);
	data->size_a++;
	data->ops_count++;
	write(1, "pa\n", 3);
}

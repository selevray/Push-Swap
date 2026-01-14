/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:16:23 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 16:37:46 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker.h"

void	ops_sb(t_data *data)
{
	if (data->size_b < 2)
		return ;
	swap(&data->pile_b);
}

void	ops_rb(t_data *data)
{
	if (data->size_b < 2)
		return ;
	data->pile_b = data->pile_b->next;
}

void	ops_rrb(t_data *data)
{
	t_node	*last;

	if (data->size_b < 2)
		return ;
	last = find_last(data->pile_b);
	data->pile_b = last;
}

void	ops_pb(t_data *data)
{
	t_node	*move;
	t_node	*last_a;

	if (data->pile_a == NULL)
		return ;
	move = data->pile_a;
	if (data->size_a == 1)
		data->pile_a = NULL;
	else
	{
		last_a = find_last(data->pile_a);
		data->pile_a = data->pile_a->next;
		last_a->next = data->pile_a;
	}
	data->size_a--;
	move->next = move;
	add_top(&data->pile_b, move);
	data->size_b++;
}

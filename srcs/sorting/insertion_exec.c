/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:46:58 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 12:03:44 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both_down(t_data *data, int pos_b, int pos_a)
{
	int	rrb_count;
	int	rra_count;

	rrb_count = data->size_b - pos_b;
	rra_count = data->size_a - pos_a;
	while (rrb_count > 0 && rra_count > 0)
	{
		rrr(data);
		rrb_count--;
		rra_count--;
	}
	while (rrb_count > 0)
	{
		rrb(data);
		rrb_count--;
	}
	while (rra_count > 0)
	{
		rra(data);
		rra_count--;
	}
}

void	rotate_both(t_data *data, int *pos_b, int *pos_a)
{
	while (*pos_b > 0 && *pos_a > 0)
	{
		rr(data);
		(*pos_b)--;
		(*pos_a)--;
	}
}

void	rotate_both_up(t_data *data, int *pos_b, int *pos_a)
{
	while (*pos_b > 0 && *pos_a > 0)
	{
		rr(data);
		(*pos_b)--;
		(*pos_a)--;
	}
	while (*pos_b > 0)
	{
		rb(data);
		(*pos_b)--;
	}
	while (*pos_a > 0)
	{
		ra(data);
		(*pos_a)--;
	}
}

void	rotate_a(t_data *data, int pos)
{
	if (pos <= data->size_a / 2)
	{
		while (pos-- > 0)
			ra(data);
	}
	else
	{
		while (pos++ < data->size_a)
			rra(data);
	}
}

void	rotate_b(t_data *data, int pos)
{
	if (pos <= data->size_b / 2)
	{
		while (pos-- > 0)
			rb(data);
	}
	else
	{
		while (pos++ < data->size_b)
			rrb(data);
	}
}

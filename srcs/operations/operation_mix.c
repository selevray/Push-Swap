/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_mix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:10 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/16 13:52:10 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_data *data)
{
	if (data->size_a < 2 || data->size_b < 2)
		return ;
	swap(&data->pile_a);
	swap(&data->pile_b);
	write(1, "ss\n", 3);
}

void	rr(t_data *data)
{
	if (data->size_a < 2 || data->size_b < 2)
		return ;
	reverse(&data->pile_a);
	reverse(&data->pile_b);
	write(1, "rr\n", 3);
}

void	rrr(t_data *data)
{
	t_node	*last_a;
	t_node	*last_b;

	if (data->size_a < 2 || data->size_b < 2)
		return ;
	last_a = find_last(data->pile_a);
	data->pile_a = last_a;
	last_b = find_last(data->pile_b);
	data->pile_b = last_b;
	write(1, "rrr\n", 4);
}

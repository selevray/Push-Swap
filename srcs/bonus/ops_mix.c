/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_mix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:17:15 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 17:24:13 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker.h"

void	ops_ss(t_data *data)
{
	if (data->size_a < 2 || data->size_b < 2)
		return ;
	swap(&data->pile_a);
	swap(&data->pile_b);
}

void	ops_rr(t_data *data)
{
	if (data->size_a < 2 || data->size_b < 2)
		return ;
	data->pile_a = data->pile_a->next;
	data->pile_b = data->pile_b->next;
}

void	ops_rrr(t_data *data)
{
	t_node	*last_a;
	t_node	*last_b;

	if (data->size_a < 2 || data->size_b < 2)
		return ;
	last_a = find_last(data->pile_a);
	data->pile_a = last_a;
	last_b = find_last(data->pile_b);
	data->pile_b = last_b;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selevray <selevray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:45:38 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/19 15:33:33 by selevray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_at(t_node *pile, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		pile = pile->next;
		i++;
	}
	return (pile->index);
}

int	find_min_pos(t_data *data)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		i;

	current = data->pile_a;
	min_index = current->index;
	min_pos = 0;
	i = 0;
	while (i < data->size_a)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

int	find_target_pos(t_data *data, int b_index)
{
	t_node	*current;
	int		i;
	int		target_index;
	int		target_pos;

	current = data->pile_a;
	target_index = data->size_a + data->size_b;
	target_pos = 0;
	i = 0;
	while (i < data->size_a)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = i;
		}
		current = current->next;
		i++;
	}
	if (target_index == data->size_a + data->size_b)
		target_pos = find_min_pos(data);
	return (target_pos);
}

int	calc_cost(t_data *data, int pos_b, int pos_a)
{
	int	cost_b;
	int	cost_a;

	if (pos_b <= data->size_b / 2)
		cost_b = pos_b;
	else
		cost_b = data->size_b - pos_b;
	if (pos_a <= data->size_a / 2)
		cost_a = pos_a;
	else
		cost_a = data->size_a - pos_a;
	if ((pos_b <= data->size_b / 2) == (pos_a <= data->size_a / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	find_best_move(t_data *data, int *pos_b, int *pos_a)
{
	int	i;
	int	cost;
	int	min_cost;
	int	target;

	i = 0;
	min_cost = data->size_a + data->size_b;
	while (i < data->size_b)
	{
		target = find_target_pos(data, get_index_at(data->pile_b, i));
		cost = calc_cost(data, i, target);
		if (cost < min_cost)
		{
			min_cost = cost;
			*pos_b = i;
			*pos_a = target;
		}
		i++;
	}
}

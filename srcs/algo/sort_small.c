/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:09:48 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 12:09:50 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->pile_a->value > data->pile_a->next->value)
		sa(data);
}

void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->pile_a->value;
	b = data->pile_a->next->value;
	c = data->pile_a->next->next->value;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a < b && b > c && a < c)
	{
		sa(data);
		ra(data);
	}
	else if (a < b && b > c && a > c)
		rra(data);
}

void	sort_five(t_data *data)
{
	int	min;

	while (data->size_a > 3)
	{
		min = find_min(data->pile_a, data->size_a);
		bring_to_top(data, min);
		pb(data);
	}
	sort_three(data);
	while (data->size_b > 0)
		pa(data);
}

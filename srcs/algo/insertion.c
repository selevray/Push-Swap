/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:45:33 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 12:08:00 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exec_rotations(t_data *data, int pos_b, int pos_a)
{
	int	b_up;
	int	a_up;

	b_up = (pos_b <= data->size_b / 2);
	a_up = (pos_a <= data->size_a / 2);
	if (b_up && a_up)
		rotate_both_up(data, &pos_b, &pos_a);
	else if (!b_up && !a_up)
		rotate_both_down(data, pos_b, pos_a);
	else
	{
		rotate_b(data, pos_b);
		rotate_a(data, pos_a);
	}
}

void	final_rotate(t_data *data)
{
	int	min_pos;

	min_pos = find_min_pos(data);
	rotate_a(data, min_pos);
}

void	insertion_sort(t_data *data)
{
	int	pos_b;
	int	pos_a;

	while (data->size_a > 3)
		pb(data);
	if (data->size_a == 3)
		sort_three(data);
	else if (data->size_a == 2)
		sort_two(data);
	while (data->size_b > 0)
	{
		pos_b = 0;
		pos_a = 0;
		find_best_move(data, &pos_b, &pos_a);
		exec_rotations(data, pos_b, pos_a);
		pa(data);
	}
	final_rotate(data);
}

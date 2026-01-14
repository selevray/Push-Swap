/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:45:17 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 11:45:25 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	bits;
	int	max_value;

	bits = 0;
	max_value = size - 1;
	while (max_value > 0)
	{
		max_value = max_value >> 2;
		bits++;
	}
	return (bits);
}

int	get_bit(int num, int bit_position)
{
	return ((num >> (bit_position * 2)) & 3);
}

void	radix_pile_a(t_data *piles, int size_a, int two_bits, int bit)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		two_bits = get_bit(piles->pile_a->index, bit);
		if (two_bits < 2)
			pb(piles);
		else
			ra(piles);
		i++;
	}
}

void	radix_sort(t_data *piles)
{
	int	max_bits;
	int	bit;
	int	size_a;
	int	i;
	int	two_bits;

	max_bits = get_max_bits(piles->size_a);
	bit = 0;
	while (bit < max_bits)
	{
		size_a = piles->size_a;
		radix_pile_a(piles, size_a, two_bits, bit);
		size_a = piles->size_b;
		i = 0;
		while (i < size_a)
		{
			two_bits = get_bit(piles->pile_b->index, bit);
			if (two_bits % 2 == 0)
				rb(piles);
			i++;
		}
		while (piles->size_b > 0)
			pa(piles);
		bit++;
	}
}

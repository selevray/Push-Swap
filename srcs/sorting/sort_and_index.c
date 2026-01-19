/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 23:29:21 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 23:29:23 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort_array(int *tab, int size)
{
	int	i;
	int	temp;
	int	swap;

	swap = 1;
	while (swap)
	{
		i = 1;
		swap = 0;
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
				swap = 1;
			}
			i++;
		}
	}
}

int	*copy_stack_to_array(t_node *pile, int size)
{
	int		*tab;
	t_node	*current;
	int		i;

	if (pile == NULL || size == 0)
		return (NULL);
	tab = malloc(size * sizeof(int));
	if (tab == NULL)
		return (NULL);
	current = pile;
	i = 0;
	while (i < size)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	return (tab);
}

int	find_index(int *tab, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(t_node *pile, int size, int *median)
{
	t_node	*current;
	int		i;
	int		index;
	int		*tab;

	i = 0;
	index = 0;
	tab = copy_stack_to_array(pile, size);
	bubble_sort_array(tab, size);
	current = pile;
	i = 0;
	while (i < size)
	{
		index = find_index(tab, size, current->value);
		current->index = index;
		current = current->next;
		i++;
	}
	*median = tab[size / 2];
	free(tab);
}

// void	print_stack(t_data *data)
// {
// 	int		i;
// 	t_node	*current;

// #include <stdio.h>
// 	i = 0;
// 	current = data->pile_a;
// 	while (i < data->size_a)
// 	{
// 		printf("%d ", current->value);
// 		i++;
// 		current = current->next;
// 	}
// }
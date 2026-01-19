/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selevray <selevray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:41:31 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/19 15:34:05 by selevray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_node	*find_last(t_node *top)
{
	t_node	*current;

	if (top == NULL)
		return (NULL);
	current = top;
	while (current->next != top)
		current = current->next;
	return (current);
}

void	add_top(t_node **top, t_node *new)
{
	t_node	*last;

	if (*top == NULL)
	{
		*top = new;
		new->next = new;
		return ;
	}
	last = find_last(*top);
	new->next = *top;
	last->next = new;
	*top = new;
}

void	add_bottom(t_node **top, t_node *new)
{
	t_node	*last;
	t_node	*first;

	if (*top == NULL)
	{
		*top = new;
		new->next = new;
		return ;
	}
	first = *top;
	last = find_last(*top);
	new->next = first;
	last->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:34:22 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/16 14:00:34 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **pile)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (*pile == NULL || (*pile)->next == *pile)
		return ;
	first = *pile;
	second = first->next;
	last = find_last(*pile);
	first->next = second->next;
	second->next = first;
	last->next = second;
	*pile = second;
}

void	reverse(t_node **pile)
{
	if (!pile || !*pile || *pile == (*pile)->next)
		return ;
	*pile = (*pile)->next;
}

void	reverse_rotate(t_node **pile, int size)
{
	t_node	*last;

	if (size < 2)
		return ;
	last = find_last(*pile);
	*pile = last;
}

t_node	*detach_first(t_node **src, int size_src)
{
	t_node	*to_push;
	t_node	*last;

	to_push = *src;
	if (size_src == 1)
		*src = NULL;
	else
	{
		last = find_last(*src);
		*src = to_push->next;
		last->next = *src;
	}
	return (to_push);
}

void	push(t_node **src, t_node **dest, int *size_src, int *size_dest)
{
	t_node	*to_push;

	if (*size_src == 0)
		return ;
	to_push = detach_first(src, *size_src);
	if (*dest == NULL)
	{
		*dest = to_push;
		to_push->next = to_push;
	}
	else
	{
		to_push->next = *dest;
		find_last(*dest)->next = to_push;
		*dest = to_push;
	}
	(*size_src)--;
	(*size_dest)++;
}

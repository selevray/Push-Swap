/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:34:22 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 16:15:24 by bzeloxx          ###   ########.fr       */
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

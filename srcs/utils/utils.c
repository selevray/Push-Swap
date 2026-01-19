/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selevray <selevray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:40:02 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/19 15:34:09 by selevray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_node *pile, int value, int size)
{
	int		i;
	t_node	*current;

	if (pile == NULL)
		return (0);
	current = pile;
	i = 0;
	while (i < size)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i
			+ 1] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	// if (str[i] = "2147483648")
	// 	return 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_sorted(t_data *data)
{
	t_node	*current;
	int		i;

	if (data->pile_a == NULL || data->size_a <= 1)
		return (1);
	if (data->pile_b != NULL || data->size_b > 0)
		return (0);
	current = data->pile_a;
	i = 0;
	while (i < data->size_a - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

void	free_stack(t_node *pile, int size)
{
	t_node	*current;
	t_node	*next;
	t_node	*last;

	if (!pile || size == 0)
		return ;
	last = find_last(pile);
	last->next = NULL;
	current = pile;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

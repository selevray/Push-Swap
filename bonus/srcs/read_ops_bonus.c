/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selevray <selevray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:37:56 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/19 15:32:49 by selevray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	execute_instruction(t_data *data, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap(&data->pile_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap(&data->pile_b);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		swap(&data->pile_a);
		swap(&data->pile_b);
	}
	else if (ft_strcmp(line, "pa\n") == 0)
		push(&data->pile_b, &data->pile_a, &data->size_b, &data->size_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(&data->pile_a, &data->pile_b, &data->size_a, &data->size_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		reverse(&data->pile_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		reverse(&data->pile_b);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		reverse(&data->pile_a);
		reverse(&data->pile_b);
	}
	else
		return (execute_instruction_2(data, line));
	return (1);
}

int	execute_instruction_2(t_data *data, char *line)
{
	if (ft_strcmp(line, "rra\n") == 0)
		reverse_rotate(&data->pile_a, data->size_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		reverse_rotate(&data->pile_b, data->size_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		reverse_rotate(&data->pile_a, data->size_a);
		reverse_rotate(&data->pile_b, data->size_b);
	}
	else
		return (0);
	return (1);
}

int	read_and_execute(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_instruction(data, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

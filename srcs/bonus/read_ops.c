/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:37:56 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 17:23:56 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/checker.h"

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
		ops_sa(data);
	else if (ft_strcmp(line, "sb\n") == 0)
		ops_sb(data);
	else if (ft_strcmp(line, "ss\n") == 0)
	{
		ops_sa(data);
		ops_sb(data);
	}
	else if (ft_strcmp(line, "pa\n") == 0)
		ops_pa(data);
	else if (ft_strcmp(line, "pb\n") == 0)
		ops_pb(data);
	else if (ft_strcmp(line, "ra\n") == 0)
		ops_ra(data);
	else if (ft_strcmp(line, "rb\n") == 0)
		ops_rb(data);
	else if (ft_strcmp(line, "rr\n") == 0)
	{
		ops_ra(data);
		ops_rb(data);
	}
	else
		return (execute_instruction_2(data, line));
	return (1);
}

int	execute_instruction_2(t_data *data, char *line)
{
	if (ft_strcmp(line, "rra\n") == 0)
		ops_rra(data);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ops_rrb(data);
	else if (ft_strcmp(line, "rrr\n") == 0)
	{
		ops_rra(data);
		ops_rrb(data);
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

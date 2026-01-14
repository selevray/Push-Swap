/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:35:52 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 11:39:19 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_and_add(char *str, t_data *data)
{
	long	number;
	t_node	*node;

	if (!is_valid_number(str))
		return (0);
	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	if (has_duplicate(data->pile_a, (int)number, data->size_a))
		return (0);
	node = new_node((int)number);
	if (node == NULL)
		return (0);
	add_bottom(&data->pile_a, node);
	data->size_a++;
	return (1);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	parse_single_string(char *str, t_data *data)
{
	char	**tab;
	int		i;

	tab = ft_split(str, ' ');
	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		if (!validate_and_add(tab[i], data))
		{
			free_tab(tab);
			return (0);
		}
		i++;
	}
	free_tab(tab);
	return (1);
}

static int	parse_multiple_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!validate_and_add(argv[i], data))
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (1);
	else if (argc == 2)
		return (parse_single_string(argv[1], data));
	else
		return (parse_multiple_args(argc, argv, data));
}

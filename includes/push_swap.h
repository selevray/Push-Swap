/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:43:04 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 17:12:57 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "algorithms.h"
# include "operations.h"
# include "bonus/checker.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_data
{
	t_node			*pile_a;
	t_node			*pile_b;
	int				size_a;
	int				size_b;
	int				ops_count;
}					t_data;

t_node				*new_node(int nb);
void				add_top(t_node **top, t_node *new);
void				add_bottom(t_node **top, t_node *new);
void				swap(t_node **pile);
t_node				*find_last(t_node *top);
void				print_stack(t_node *pile, char *name, int size);
int					parse_arguments(int argc, char **argv, t_data *data);
void				free_stack(t_node *pile, int size);

int					has_duplicate(t_node *pile, int value, int size);
int					is_valid_number(char *str);
long				ft_atol(const char *str);
int					find_min(t_node *pile, int size);
int					is_sorted(t_data *data);
void				bring_to_top(t_data *piles, int value);

char				**ft_split(char const *str, char charset);

#endif

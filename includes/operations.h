/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:43:01 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/16 15:16:23 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_node	t_node;
typedef struct s_data	t_data;

void	swap(t_node **pile);
void	reverse(t_node **pile);
void	reverse_rotate(t_node **pile, int size);
t_node	*detach_first(t_node **src, int size_src);
void	push(t_node **src, t_node **dest, int *size_src, int *size_dest);

void	sa(t_data *data);
void	ra(t_data *data);
void	rra(t_data *data);
void	pa(t_data *data);

void	sb(t_data *data);
void	rb(t_data *data);
void	rrb(t_data *data);
void	pb(t_data *data);

void	ss(t_data *data);
void	rr(t_data *data);
void	rrr(t_data *data);

#endif

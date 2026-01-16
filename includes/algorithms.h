/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:42:55 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 23:36:35 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

typedef struct s_node	t_node;
typedef struct s_data	t_data;

void					sort_two(t_data *piles);
void					sort_three(t_data *piles);
void					sort_five(t_data *piles);

void					bubble_sort_array(int *tab, int size);
int						*copy_stack_to_array(t_node *pile, int size);
int						find_index(int *tab, int size, int value);
void					index_stack(t_node *pile, int size, int *median);
int						get_max_bits(int size);
int						get_two_bits(int num, int bit_position);

void					rotate_both_down(t_data *data, int pos_b, int pos_a);
void					rotate_both(t_data *data, int *pos_b, int *pos_a);
void					rotate_both_up(t_data *data, int *pos_b, int *pos_a);
void					rotate_a(t_data *data, int pos);
void					rotate_b(t_data *data, int pos);

int						get_index_at(t_node *pile, int pos);
int						find_min_pos(t_data *data);
int						find_target_pos(t_data *data, int b_index);
int						calc_cost(t_data *data, int pos_b, int pos_a);
void					find_best_move(t_data *data, int *pos_b, int *pos_a);

void					exec_rotations(t_data *data, int pos_b, int pos_a);
void					final_rotate(t_data *data);
void					insertion_sort(t_data *data, int median);

#endif

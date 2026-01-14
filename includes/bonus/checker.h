/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:57:04 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 17:16:44 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../../srcs/bonus/get-next-line/get_next_line.h"

void	ops_sa(t_data *data);
void	ops_ra(t_data *data);
void	ops_rra(t_data *data);
void	ops_pa(t_data *data);
void	ops_sb(t_data *data);
void	ops_rb(t_data *data);
void	ops_rrb(t_data *data);
void	ops_pb(t_data *data);
void	ops_ss(t_data *data);
void	ops_rr(t_data *data);
void	ops_rrr(t_data *data);

int		ft_strcmp(char *s1, char *s2);
int		read_and_execute(t_data *data);
int		execute_instruction(t_data *data, char *line);
int		execute_instruction_2(t_data *data, char *line);

#endif
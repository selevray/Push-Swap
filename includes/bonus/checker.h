/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:57:04 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/16 17:06:14 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "../../srcs/bonus/get-next-line/get_next_line.h"

int		ft_strcmp(char *s1, char *s2);
int		read_and_execute(t_data *data);
int		execute_instruction(t_data *data, char *line);
int		execute_instruction_2(t_data *data, char *line);

#endif
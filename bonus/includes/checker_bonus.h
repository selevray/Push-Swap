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
#define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include "../../includes/push_swap.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#ifndef FD_MAX
#define FD_MAX 1024
#endif

typedef struct s_gnl
{
    char *str_static;
    char *buffer;
    char *temp;
    int bytes_read;
    int fd;
} t_gnl;

/* get_next_line.c */
char *get_next_line(int fd);

/* get_next_line_utils.c */
size_t ft_strlen(const char *str);
char *ft_strchr(const char *string, int searchedChar);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_substr(char const *s, unsigned int start, size_t len);

int ft_strcmp(char *s1, char *s2);
int read_and_execute(t_data *data);
int execute_instruction(t_data *data, char *line);
int execute_instruction_2(t_data *data, char *line);

#endif
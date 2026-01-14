/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:42:59 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 11:43:36 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *format, ...) __attribute__((format(printf, 1,
					2)));
int		ft_format(char c, va_list args);

size_t	ft_strlen(const char *str);
int		ft_print_char(char c);
int		ft_print_str(char *string);

int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned long n, int format);
int		ft_numlen(long n);
int		ft_unumlen(unsigned int n);
int		ft_print_ptr(unsigned long n);

#endif
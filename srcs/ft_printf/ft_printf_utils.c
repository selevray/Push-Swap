/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:49 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 11:45:00 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *string)
{
	int	len;

	if (!string)
		string = "(null)";
	len = ft_strlen(string);
	if (write(1, string, len) == -1)
		return (-1);
	return (len);
}

int	ft_print_nbr(int n)
{
	char		c;
	int			len;
	long long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		len++;
	}
	if (nb >= 10)
	{
		len += ft_print_nbr(nb / 10);
		if (len == -1)
			return (-1);
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_unsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len = ft_print_unsigned(n / 10);
		if (len == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_hex(unsigned long n, int format)
{
	char	*base;
	int		count;

	if (format)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
	{
		count = ft_print_hex(n / 16, format);
		if (count == -1)
			return (-1);
	}
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	return (count + 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzeloxx <bzeloxx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:44:41 by bzeloxx           #+#    #+#             */
/*   Updated: 2026/01/14 11:44:43 by bzeloxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	is_existe(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_ptr((unsigned long)va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex((unsigned long)va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_print_hex((unsigned long)va_arg(args, unsigned int), 0));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_existe(format[i + 1]))
		{
			count += ft_format(format[i + 1], args);
			i++;
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%%%\n");
// 	ft_printf("%%%\n");
// }
// #include <stdio.h>

// int	main(void)
// {
// 	// Test character
// 	ft_printf("Character test: %c\n", '\0');
// 	printf("Character test: %c\n", '\0');

// 	// Test string
// 	ft_printf("String test: %s\n", "");
// 	printf("String test: %s\n", "");

// 	// // Test pointer2.0
// 	// int *x = NULL;
// 	// printf( "test: %i\n", ft_printf("Pointer test: %p\n", NULL));
// 	// printf( "test: %i\n", printf("Pointer test: %p\n", NULL));

// 	// Test pointer
// 	int x = 42;
// 	ft_printf("Pointer test: %p\n", &x);
// 	printf("Pointer test: %p\n", &x);

// 	// Test integer (decimal)
// 	ft_printf("Integer test: %d\n", 12345);
// 	printf("Integer test: %d\n", 12345);

// 	// Test integer (signed)
// 	ft_printf("Signed integer test: %i\n", -6789);
// 	printf("Signed integer test: %i\n", -6789);

// 	// Test unsigned integer
// 	ft_printf("Unsigned integer test: %u\n", 3000000000u);
// 	printf("Unsigned integer test: %u\n", 3000000000u);

// 	// Test hexadecimal (lowercase)
// 	ft_printf("Hexadecimal test (lowercase): %x\n", 255);
// 	printf("Hexadecimal test (lowercase): %x\n", 255);

// 	// Test hexadecimal (uppercase)
// 	ft_printf("Hexadecimal test (uppercase): %X\n", 255);
// 	printf("Hexadecimal test (uppercase): %X\n", 255);

// 	// Test mixing all formats
// 	ft_printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n", 'Z', "42", &x, 42,
// 		-42, 42u, 42, 42);
// 	printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n", 'Z', "42", &x, 42, -42,
// 		42u, 42, 42);
// 	return (0);
// }

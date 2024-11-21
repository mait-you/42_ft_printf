/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:21:40 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/21 16:21:12 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(const char f, va_list args)
{
	int		re_value;

	re_value = 0;
	if (f == '%')
		re_value = ft_putchar(f);
	else if (f == 'c')
		re_value = ft_putchar(va_arg(args, int));
	else if (f == 's')
		re_value = ft_putstr(va_arg(args, char *));
	else if (f == 'p')
	{
		re_value = ft_putstr("0x");
		if (re_value == -1)
			return (re_value);
		re_value += ft_putadress(va_arg(args, unsigned long));
		if (re_value == 1)
			return (-1);
	}
	else if (f == 'd' || f == 'i')
		re_value = ft_putnbr(va_arg(args, int));
	else if (f == 'u')
		re_value = ft_putunbr(va_arg(args, unsigned int));
	else if (f == 'x' || f == 'X')
		re_value = ft_puthexa(va_arg(args, unsigned int), f);
	return (re_value);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		re_value;
	int		check_value;

	va_start(args, format);
	re_value = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			check_value = find_format(*(++format), args);
			if (check_value == -1)
				return (va_end(args), check_value);
			re_value += check_value;
		}
		else
		{
			check_value = ft_putchar(*format);
			if (check_value == -1)
				return (va_end(args), check_value);
			re_value += check_value;
		}
		format++;
	}
	return (va_end(args), re_value);
}

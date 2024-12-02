/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:21:40 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/29 11:26:59 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(const char f_search, va_list args)
{
	int		re_value;

	re_value = 0;
	if (f_search == '%')
		re_value = ft_putchr('%');
	else if (f_search == 'c')
		re_value = ft_putchr(va_arg(args, int));
	else if (f_search == 's')
		re_value = ft_putstr(va_arg(args, char *));
	else if (f_search == 'p')
	{
		re_value = ft_putstr("0x");
		re_value += ft_putadress(va_arg(args, unsigned long));
	}
	else if (f_search == 'd' || f_search == 'i')
		re_value = ft_putnbr(va_arg(args, int));
	else if (f_search == 'u')
		re_value = ft_putunbr(va_arg(args, unsigned int));
	else if (f_search == 'x' || f_search == 'X')
		re_value = ft_puthexa(va_arg(args, unsigned int), f_search);
	else
		re_value = ft_putchr(f_search);
	return (re_value);
}

static int	ft_print_extra_format(const char **f, const char *f_search, \
	t_key key, va_list args)
{
	int		re_value;

	re_value = 0;
	if ((*f_search == 'd' || *f_search == 'i' || \
		*f_search == 'X' || *f_search == 'x') && key.paddin != 1)
		re_value = ft_extra(*f_search, key, args);
	else if (key.paddin == 1)
		re_value = ft_paddin(f, f_search, key, args);
	else
		re_value = ft_print_format(*f_search, args);
	return (re_value);
}

static int	ft_extra_format(const char **f, va_list args)
{
	const char	*f_search;
	t_key		key;
	int			re_value;

	re_value = 0;
	if (ft_strchr(X_SPECIFIERS, **f))
	{
		key.plus = 0;
		key.minus = 0;
		key.spase = 0;
		key.hash = 0;
		key.paddin = 0;
		key.to_zero = 0;
		f_search = ft_skep_search(f, &key);
		re_value += ft_print_extra_format(f, f_search, key, args);
	}
	else
		re_value = ft_print_format(**f, args);
	return (re_value);
}

static void	ft_printf_hub(const char *format, va_list args, \
	int *re_value, int *check_value)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			*check_value = ft_extra_format(&format, args);
			if (*check_value == -1)
				return ;
			*re_value += *check_value;
		}
		else if (*format && *format != '%')
		{
			*check_value = ft_putchr(*format);
			if (*check_value == -1)
				return ;
			*re_value += *check_value;
		}
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		re_value;
	int		check_value;

	re_value = write(1, "", 0);
	if (re_value == -1)
		return (re_value);
	re_value = 0;
	check_value = 0;
	va_start(args, format);
	ft_printf_hub(format, args, &re_value, &check_value);
	if (check_value == -1)
	{
		ft_putnchr('\b', re_value);
		return (va_end(args), check_value);
	}
	return (va_end(args), re_value);
}

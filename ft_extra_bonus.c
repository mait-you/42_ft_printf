/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:28:46 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 09:11:07 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa_extra(unsigned int nb, char f, t_key key)
{
	int	re_value;

	re_value = 0;
	if (nb == 0)
		return (ft_putnbr(nb));
	if (f == 'x' && key.hash == 1)
		re_value += ft_putstr("0x");
	if (re_value == -1)
		return (re_value);
	if (f == 'X' && key.hash == 1)
		re_value += ft_putstr("0X");
	if (re_value == -1)
		return (re_value);
	re_value += ft_puthexa(nb, f);
	return (re_value);
}

static int	ft_putnbr_extra(int nb, t_key key)
{
	int	re_value;

	re_value = 0;
	if (key.plus == 1 && nb >= 0)
		re_value = ft_putchr('+');
	if (key.spase == 1 && key.plus == 0 && nb >= 0)
		re_value = ft_putchr(' ');
	re_value += ft_putnbr(nb);
	return (re_value);
}

int	ft_extra(const char f_search, t_key key, va_list args)
{
	int	re_value;

	re_value = 0;
	if (f_search == 'd' || f_search == 'i')
		re_value = ft_putnbr_extra(va_arg(args, int), key);
	else if (f_search == 'x' || f_search == 'X')
	{
		re_value = ft_puthexa_extra(va_arg(args, unsigned int), f_search, key);
	}
	return (re_value);
}

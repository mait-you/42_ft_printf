/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:33:13 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/20 11:50:17 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(int nb)
{
	int	re_value;

	re_value = 0;
	if (nb >= 10)
	{
		re_value += ft_putnbr_recursive(nb / 10);
		if (re_value == -1)
			return (-1);
		re_value += ft_putnbr_recursive(nb % 10);
		if (re_value == -1)
			return (-1);
	}
	else
	{
		re_value += ft_putchar(nb + '0');
		if (re_value == -1)
			return (-1);
	}
	return (re_value);
}

int	ft_putnbr(int nb)
{
	int	re_value;

	re_value = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		re_value += ft_putchar('-');
		if (re_value == -1)
			return (-1);
		nb = -nb;
	}
	re_value += ft_putnbr_recursive(nb);
	return (re_value);
}

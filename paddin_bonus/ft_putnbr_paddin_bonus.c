/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_paddin_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:47:42 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 11:12:01 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long	num_len(long n)
{
	long	l;

	l = 0;
	if (n <= 0)
	{
		n = -n;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static int	ft_putnbr_p_aligned_left(int nb, long paddin, t_key key)
{
	int	re_value;

	re_value = 0;
	if (key.plus == 1 && nb >= 0)
	{
		paddin--;
		re_value += ft_putchr('+');
	}
	re_value = ft_putnbr(nb);
	re_value += ft_putnchr(' ', paddin);
	return (re_value);
}

static int	ft_putnbr_p_aligned_right(int nb, long paddin, t_key key)
{
	int	re_value;

	re_value = 0;
	if (key.plus && nb >= 0)
	{
		paddin--;
		if (!key.to_zero)
			re_value += ft_putnchr(' ', paddin);
		re_value += ft_putchr('+');
	}
	if (key.to_zero && nb < 0)
		re_value += ft_putchr('-');
	if (key.to_zero)
		re_value += ft_putnchr('0', paddin);
	else
		re_value += ft_putnchr(' ', paddin);
	if (key.to_zero && nb == INT_MIN)
		re_value += ft_putstr("2147483648");
	else if (key.to_zero && nb < 0)
		re_value += ft_putnbr(-nb);
	else
		re_value += ft_putnbr(nb);
	return (re_value);
}

int	ft_putnbr_p(int nb, t_key key, long space_len)
{
	int		re_value;
	long	nb_len;
	long	paddin;

	re_value = 0;
	nb_len = num_len(nb);
	paddin = space_len - nb_len;
	if (paddin < 0)
		paddin = 0;
	if (key.minus == 1)
		re_value += ft_putnbr_p_aligned_left(nb, paddin, key);
	else
		re_value += ft_putnbr_p_aligned_right(nb, paddin, key);
	return (re_value);
}

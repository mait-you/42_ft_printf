/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_paddin_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:57 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 11:11:08 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long	hex_len(unsigned int nb)
{
	long	re_value;

	re_value = 1;
	while (nb >= 16)
	{
		nb /= 16;
		re_value++;
	}
	return (re_value);
}

static int	ft_putunbr_p_aligned_left(unsigned int nb, long paddin, \
	t_key key, char f_search)
{
	int	re_value;

	re_value = 0;
	if (f_search == 'x' && key.hash == 1)
		re_value += ft_putstr("0x");
	if (f_search == 'X' && key.hash == 1)
		re_value += ft_putstr("0X");
	re_value += ft_puthexa(nb, f_search);
	re_value += ft_putnchr(' ', paddin);
	return (re_value);
}

static int	ft_putunbr_p_aligned_right(unsigned int nb, long paddin, \
	t_key key, char f_search)
{
	int	re_value;

	re_value = 0;
	if (key.to_zero)
	{
		if (f_search == 'x' && key.hash)
			re_value += ft_putstr("0x");
		if (f_search == 'X' && key.hash)
			re_value += ft_putstr("0X");
		re_value += ft_putnchr('0', paddin);
	}
	else
	{
		re_value += ft_putnchr(' ', paddin);
		if (f_search == 'x' && key.hash == 1)
			re_value += ft_putstr("0x");
		if (f_search == 'X' && key.hash == 1)
			re_value += ft_putstr("0X");
	}
	re_value += ft_puthexa(nb, f_search);
	return (re_value);
}

int	ft_puthexa_p(unsigned int nb, t_key key, long space_len, char f_search)
{
	int		re_value;
	long	nb_len;
	long	paddin;

	re_value = 0;
	nb_len = hex_len(nb);
	paddin = space_len - nb_len;
	if (paddin < 0)
		paddin = 0;
	if (key.hash)
		paddin -= 2;
	if (key.minus == 1)
		re_value += ft_putunbr_p_aligned_left(nb, paddin, key, f_search);
	else
		re_value += ft_putunbr_p_aligned_right(nb, paddin, key, f_search);
	return (re_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_paddin_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:46:28 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 11:08:23 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long	hex_len(unsigned long nb)
{
	long	re_value;

	re_value = 3;
	while (nb >= 16)
	{
		nb /= 16;
		re_value++;
	}
	return (re_value);
}

static int	ft_putadress_p_aligned_left(unsigned long nb, long paddin)
{
	int	re_value;

	re_value = 0;
	re_value = ft_putstr("0x");
	re_value += ft_putadress(nb);
	re_value += ft_putnchr(' ', paddin);
	return (re_value);
}

static int	ft_putadress_p_aligned_right(unsigned long nb, long paddin)
{
	int	re_value;

	re_value = 0;
	re_value += ft_putnchr(' ', paddin);
	re_value += ft_putstr("0x");
	re_value += ft_putadress(nb);
	return (re_value);
}

int	ft_putadress_p(unsigned long nb, t_key key, long space_len)
{
	int		re_value;
	long	nb_len;
	long	paddin;

	re_value = 0;
	nb_len = hex_len(nb);
	paddin = space_len - nb_len;
	if (paddin < 0)
		paddin = 0;
	if (key.minus == 1)
		re_value += ft_putadress_p_aligned_left(nb, paddin);
	else
		re_value += ft_putadress_p_aligned_right(nb, paddin);
	return (re_value);
}

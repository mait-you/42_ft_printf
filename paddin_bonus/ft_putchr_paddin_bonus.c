/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr_paddin_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:46:31 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 11:09:11 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putchr_p_aligned_left(char c, long space_len)
{
	int	re_value;

	re_value = 0;
	re_value += ft_putchr(c);
	re_value += ft_putnchr(' ', space_len);
	return (re_value);
}

static int	ft_putchr_p_aligned_right(char c, long space_len)
{
	int	re_value;

	re_value = 0;
	re_value += ft_putnchr(' ', space_len);
	re_value += ft_putchr(c);
	return (re_value);
}

int	ft_putchr_p(char c, t_key key, long space_len)
{
	int		re_value;

	re_value = 0;
	if (key.minus == 1)
		re_value += ft_putchr_p_aligned_left(c, --space_len);
	else
		re_value += ft_putchr_p_aligned_right(c, --space_len);
	return (re_value);
}

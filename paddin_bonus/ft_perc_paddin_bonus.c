/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_paddin_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:13:53 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 11:04:05 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putchr_p_aligned_left(long space_len, char f_search, t_key key)
{
	int	re_value;

	re_value = 0;
	re_value += ft_putchr(f_search);
	if (key.to_zero == 1 && key.minus == 0)
		re_value += ft_putnchr('0', space_len);
	else
		re_value += ft_putnchr(' ', space_len);
	return (re_value);
}

static int	ft_putchr_p_aligned_right(long space_len, char f_search, t_key key)
{
	int	re_value;

	re_value = 0;
	if (key.to_zero == 1 && key.minus == 0)
		re_value += ft_putnchr('0', space_len);
	else
		re_value += ft_putnchr(' ', space_len);
	re_value += ft_putchr(f_search);
	return (re_value);
}

int	ft_perc_p(t_key key, long space_len, char f_search)
{
	int		re_value;

	re_value = 0;
	if (key.minus == 1)
		re_value += ft_putchr_p_aligned_left(--space_len, f_search, key);
	else
		re_value += ft_putchr_p_aligned_right(--space_len, f_search, key);
	return (re_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_paddin_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:00:52 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/28 11:12:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putchr_p_aligned_left(char *str, long space_len, long str_len)
{
	int	re_value;

	re_value = 0;
	re_value += ft_putstr(str);
	if (space_len - str_len > 0)
		re_value += ft_putnchr(' ', space_len - str_len);
	return (re_value);
}

static int	ft_putchr_p_aligned_right(char *str, long space_len, long str_len)
{
	int	re_value;

	re_value = 0;
	if (space_len - str_len > 0)
		re_value += ft_putnchr(' ', space_len - str_len);
	re_value += ft_putstr(str);
	return (re_value);
}

int	ft_putstr_p(char *str, t_key key, long space_len)
{
	int		re_value;
	long	str_len;

	re_value = 0;
	str_len = ft_strlen(str);
	if (key.minus == 1)
		re_value += ft_putchr_p_aligned_left(str, space_len, str_len);
	else
		re_value += ft_putchr_p_aligned_right(str, space_len, str_len);
	return (re_value);
}

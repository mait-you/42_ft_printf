/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paddin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:37:55 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/30 09:20:14 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_paddin(const char **f, const char *f_search, t_key key, va_list args)
{
	int		re_value;
	size_t	space_len;

	re_value = 0;
	space_len = ft_atol(*f);
	if (space_len >= 2147483646)
		return (-1);
	else if (*f_search == '%')
		re_value = ft_perc_p(key, space_len, *f_search);
	if (*f_search == 'd' || *f_search == 'i')
		re_value = ft_putnbr_p(va_arg(args, int), key, space_len);
	else if (*f_search == 'c')
		re_value = ft_putchr_p(va_arg(args, int), key, space_len);
	else if (*f_search == 's')
		re_value = ft_putstr_p(va_arg(args, char *), key, space_len);
	else if (*f_search == 'p')
		re_value = ft_putadress_p(va_arg(args, unsigned long), key, space_len);
	else if (*f_search == 'u')
		re_value = ft_putunbr_p(va_arg(args, unsigned int), key, space_len);
	else if (*f_search == 'x' || *f_search == 'X')
		re_value = ft_puthexa_p(va_arg(args, unsigned int), \
		key, space_len, *f_search);
	*f = f_search;
	return (re_value);
}

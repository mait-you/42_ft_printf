/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:38:17 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/21 16:14:31 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int		re_value;
	int		check_value;

	if (!s)
		s = "(null)";
	re_value = 0;
	check_value = 0;
	while (*s)
	{
		check_value = ft_putchar(*s);
		if (check_value == -1)
			return (check_value);
		re_value += check_value;
		s++;
	}
	return (re_value);
}

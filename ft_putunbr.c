/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:23:51 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/21 16:14:52 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int	re_value;

	re_value = 0;
	if (nb >= 10)
	{
		re_value += ft_putunbr(nb / 10);
		if (re_value == -1)
			return (-1);
		re_value += ft_putunbr(nb % 10);
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

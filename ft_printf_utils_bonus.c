/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:42:58 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/29 11:24:50 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while (s && *s)
	{
		if (*s == cc)
			return ((char *)(s));
		s++;
	}
	return (NULL);
}

const char	*ft_skep_search(const char **f, t_key *key)
{
	const char	*ptr;

	ptr = *f;
	while (*ptr && !ft_strchr(SPECIFIERS, *ptr) && (*ptr < '0' || *ptr > '9'))
	{
		if (*ptr == '+')
			key->plus = 1;
		if (*ptr == '-')
			key->minus = 1;
		if (*ptr == ' ')
			key->spase = 1;
		if (*ptr == '#')
			key->hash = 1;
		ptr++;
	}
	*f = ptr;
	if (*ptr >= '0' && *ptr <= '9')
	{
		if (*ptr == '0')
			key->to_zero = 1;
		key->paddin = 1;
		while (*ptr && (*ptr >= '0' && *ptr <= '9'))
			ptr++;
	}
	return (ptr);
}

long	ft_atol(const char *str)
{
	long	r;
	int		i;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r);
}

int	ft_putnchr(char c, long n)
{
	int		re_value;

	re_value = 0;
	if (c == '\b')
	{
		while (n-- > 0)
			write(1, "\b \b", 3);
	}
	else
	{
		while (n-- > 0)
			re_value += ft_putchr(c);
	}
	return (re_value);
}

long	ft_strlen(const char *s)
{
	long	l;

	l = 0;
	if (!s)
		return (ft_strlen("(null)"));
	while (*(s++))
		l++;
	return (l);
}

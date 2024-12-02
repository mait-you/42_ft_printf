/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:21:35 by mait-you          #+#    #+#             */
/*   Updated: 2024/11/30 09:19:38 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

# define SPECIFIERS	"cspdiuxX%"
# define X_SPECIFIERS	"0123456789#-+ "

typedef struct t_key
{
	int		plus;
	int		minus;
	int		spase;
	int		hash;
	int		paddin;
	int		to_zero;
}			t_key;

int			ft_printf(const char *format, ...);
int			ft_putchr(char c);
int			ft_putstr(char *s);
int			ft_putadress(unsigned long nb);
int			ft_putnbr(int nb);
int			ft_putunbr(unsigned int nb);
int			ft_puthexa(unsigned int nb, char c);
int			ft_extra(const char f_search, t_key key, va_list args);
int			ft_paddin(const char **f, const char *f_search, \
	t_key key, va_list args);
int			ft_putnbr_p(int nb, t_key key, long space_len);
int			ft_putchr_p(char c, t_key key, long space_len);
int			ft_putstr_p(char *str, t_key key, long space_len);
int			ft_putadress_p(unsigned long nb, t_key key, long space_len);
int			ft_putunbr_p(unsigned int nb, t_key key, long space_len);
int			ft_puthexa_p(unsigned int nb, t_key key, \
	long space_len, char f_search);
int			ft_perc_p(t_key key, long space_len, char f_search);
char		*ft_strchr(const char *s, int c);
long		ft_atol(const char *str);
int			ft_putnchr(char c, long n);
const char	*ft_skep_search(const char **f, t_key *key);
long		ft_strlen(const char *s);

#endif

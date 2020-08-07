/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:44:51 by jmetelin          #+#    #+#             */
/*   Updated: 2020/01/27 13:50:56 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_conv
{
	int					*flags;
	int					mfw;
	int					prc;
	int					mod;
	char				conv;
	long long			sgd;
	unsigned long long	usgd;
	char				*s;
	long double			d;
	int					sign;
	int					len;
	int					ttl_len;
}				t_conv;

int				ft_printf(const char *restrict format, ...);
int				is_num_conv(int c);
void			get_conv_val(va_list ap, t_conv *conv);
void			conv_to_str(t_conv *conv);
char			*convt(unsigned long long n, int base, char *digits);
int				get_nbr_len(unsigned long long n, int base);
void			convt_dec(t_conv *conv);
void			get_conv_len(t_conv *conv);
int				print_conv(t_conv *conv, int prt);

#endif

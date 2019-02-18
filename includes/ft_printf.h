/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:56:18 by lpan              #+#    #+#             */
/*   Updated: 2019/01/07 15:56:21 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef enum	e_length
{
	none = 0,
	h,//1
	hh,//2
	l,//3
	ll,//4
	L,//5
	j,//6
	z//7
}				t_length;

typedef struct s_flags
{
	char sharp;
	char min_0;
	char plus_spce;
}							t_flags;

typedef struct	s_attribute
{
	char		conver;
	t_flags		flag;
	int			width;
	int			precis;
	t_length	length;
}				t_attribute;

int		set_attributes(char *format, t_attribute *attr, va_list ap);
char	*conver_signed_to_str(intmax_t n);
char	*conver_unsigned_to_str(uintmax_t n, int base, t_attribute *attr);
char	*check_9(int count_digit, char *str, int precis);
char *rounding_nbr(char *str, int precis);
char *rounding_nbr_excp(char *str);
int		print_specifiers(char *format, t_attribute *attr, va_list ap);
int		print_unsigned_nbr(va_list ap, int len, t_attribute *attr, int base);
int		print_signed_nbr(va_list ap, int len, t_attribute *attr);
int 	print_character(va_list ap, int len, t_attribute *attr);
int		print_string(va_list ap, int len, t_attribute *attr);
int		print_decimal(va_list ap, t_attribute *attr);
int		print_float(va_list ap, int len, t_attribute *attr);
int		print_no_specifier(char c, int len, t_attribute *attr);

#endif

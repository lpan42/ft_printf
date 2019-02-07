/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:54:50 by lpan              #+#    #+#             */
/*   Updated: 2019/01/07 13:54:54 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		print_specifiers(t_attribute *attr, va_list ap)
{
	int len;

	len = 0;
	if (attr->conver == 'c')
		len = print_character(ap, len, attr);
	if (attr->conver == 's')
		len = print_string(ap, len, attr);
	if (attr->conver == 'd' || attr->conver == 'i')
		len = print_signed_nbr(ap, len, attr);
	if (attr->conver == 'u')
		len = print_unsigned_nbr(ap, len, attr, 10);
	if (attr->conver == 'o')
		len = print_unsigned_nbr(ap, len, attr, 8);
	if (attr->conver == 'x' || attr->conver == 'X' || attr->conver == 'p')
		len = print_unsigned_nbr(ap, len, attr, 16);
	if (attr->conver == 'f')
		len = print_float(ap, len, attr);
	return(len);
}

int		ft_printf(char *format, ...)
{
	t_attribute		attr;
	va_list	ap;
	int ret; //final return of ft_printf
	int	len; //print len
	int count; //input count

	ret = 0;
	len = 0;
	count = 0;
	attr.conver = '\0';
	attr.flag.sharp = '\0';
	attr.flag.min_0 = '\0';
	attr.flag.plus_spce = '\0';
	attr.width = 0;
	attr.precis = 0;
	attr.length = none;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format != '%')
			{
				count = set_attributes(format, &attr);
				len = print_specifiers(&attr, ap);
				ret += len;
				format += count;
			}
			else
			{
				ft_putchar('%');
				ret++;
				format++;
			}
		}
		else
		{
			ft_putchar(*format);
			ret++;
			format++;
		}
	}
	va_end(ap);
	//printf("\nret: %d\n", ret);
return (ret);
}

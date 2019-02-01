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
		print_character(ap, len, attr);
	if (attr->conver == 's')
		print_string(ap, len, attr);
	if (attr->conver == 'd' || attr->conver == 'i')
		print_signed_nbr(ap, len, attr);
	if (attr->conver == 'u')
		print_unsigned_nbr(ap, len, attr, 10);
	if (attr->conver == 'o')
		print_unsigned_nbr(ap, len, attr, 8);
	if (attr->conver == 'x' || attr->conver == 'X' || attr->conver == 'p')
		print_unsigned_nbr(ap, len, attr, 16);
	if (attr->conver == 'f')
		print_float(ap, len, attr);
	return(len);
}

int		print_output(char *format, va_list ap)
{
	t_attribute		attr;
	int len = 0;
	attr.conver = '\0';
	attr.flag.sharp = '\0';
	attr.flag.min_0 = '\0';
	attr.flag.plus_spce = '\0';
	attr.width = 0;
	attr.precis = 0;
	attr.length = none;

	len = set_attributes(format, &attr);
/*
	printf("flag.sharp: %c\n", attr.flag.sharp);
	printf("flag.min_0: %c\n", attr.flag.min_0);
	printf("flag.plus_spce: %c\n", attr.flag.plus_spce);
	printf("conver: %c\n", attr.conver);
	printf("width: %d\n", attr.width);
	printf("precis: %d\n", attr.precis);
	printf("length: %d\n", attr.length);
*/
	print_specifiers(&attr, ap);
	return (len);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int count;
	int	len;

	count = 0;
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format != '%')
			{
				len = print_output(format, ap);
				count += len;
				format += len;
			}
			else
			{
				ft_putchar('%');
				format++;
			}
		}
		else
		{
			ft_putchar(*format);
			count++;
			format++;
		}
	}
	va_end(ap);
return (count);
}

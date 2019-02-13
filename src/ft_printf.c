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

int		print_specifiers(char *format, t_attribute *attr, va_list ap)
{
	int len;

	len = 0;
	if (attr->conver == 'c')
		len = print_character(ap, len, attr);
	else if (attr->conver == 's')
		len = print_string(ap, len, attr);
	else if (attr->conver == 'd' || attr->conver == 'i')
		len = print_signed_nbr(ap, len, attr);
	else if (attr->conver == 'u')
		len = print_unsigned_nbr(ap, len, attr, 10);
	else if (attr->conver == 'o')
		len = print_unsigned_nbr(ap, len, attr, 8);
	else if (attr->conver == 'x' || attr->conver == 'X' || attr->conver == 'p')
		len = print_unsigned_nbr(ap, len, attr, 16);
	else if (attr->conver == 'f')
		len = print_float(ap, len, attr);
	else if(!attr->conver)// && attr->width)
	{
		len = print_no_specifier(*format, len, attr);
	}
	return(len);
}
void init_attr(t_attribute *attr)
{
	attr->conver = '\0';
	attr->flag.sharp = '\0';
	attr->flag.min_0 = '\0';
	attr->flag.plus_spce = '\0';
	attr->width = 0;
	attr->precis = 0;
	attr->length = none;
}

int		ft_printf(char *format, ...)
{
	t_attribute		attr;
	va_list	ap;
	int ret; //final return of ft_printf
	int	len; //print len
	int count; //input count

//BONUS:
//-lengh modifier: j && z
	ret = 0;
	len = 0;
	count = 0;
	init_attr(&attr);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			//printf("format: %c\n", *format);
			//if(*format != '%')
			//printf("conver: %c\n", attr.conver);
			count = set_attributes(format, &attr);
			//printf("\ncount: %d\n", count);
			//printf("precis: %d\n", attr.precis);
			//printf("conver: %c\n", attr.conver);
			//printf("sharp: %c\n", attr.flag.sharp);
			format += count;
			len = print_specifiers(format, &attr, ap);
			//printf("len: %d\n", len);
			if(!attr.conver)
				format++;
			ret += len;
			init_attr(&attr);
			//if(count == 0 && len == 0)
			//	format++;
		}
		else
		{
			ft_putchar(*format);
			ret++;
			//printf("\nret: %d\n", ret);
			format++;
		}
	}
	va_end(ap);
	//printf("\nret: %d\n", ret);
return (ret);
}

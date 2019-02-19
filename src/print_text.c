/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:23:51 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:32:44 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int print_0_space(int len, t_attribute *attr)
{
	while (attr->width > len)
	{
		if (attr->flag.min_0 == '0' && attr->width)
			ft_putchar('0');
		if (attr->flag.min_0 != '0' && attr->width)
			ft_putchar(' ');
		len += 1;
	}
	return (len);
}

int print_character(va_list ap, int len, t_attribute *attr)
{
	char c;

	c = va_arg(ap, int);
	len = sizeof(char);
	if (!(attr->flag.min_0 == '-'))
		len = print_0_space(len, attr);
	ft_putchar(c);
	if (attr->flag.min_0 == '-')
		len = print_0_space(len, attr);
	return (len);
}

int print_string(va_list ap, int len, t_attribute *attr)
{
	char	*str;
	char	*conv_prec;

	len = 0;
	str = va_arg(ap, char *);
	//printf("str: %s\n", str);
	if(!str && !attr->width)
	{
		ft_putstr("(null)");
		return(6);
	}
	conv_prec = NULL;
	//	return (len);
	if(attr->precis > 0)// ((!(attr->flag.min_0 == '-') && (attr->precis)))
	{
		if (!(conv_prec = ft_strndup(str, attr->precis)))
			return (0);
		str = conv_prec;
	}
	if(attr->precis != -1)
		len = ft_strlen(str);
	if ((!(attr->flag.min_0 == '-') && (attr->width)))
		len = print_0_space(len, attr);
	if(attr->precis != -1)
		ft_putstr(str);
	if (attr->flag.min_0 == '-' && attr->width)
		len = print_0_space(len, attr);
	if(conv_prec)
		ft_strdel(&conv_prec);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:23:39 by lpan              #+#    #+#             */
/*   Updated: 2019/01/11 13:23:40 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned long long conver_length(va_list ap, t_attribute *attr)
{
	unsigned long long nbr;

	nbr = 0;
	if (attr->length == 1)
		nbr = (unsigned short)va_arg(ap, int);
	else if (attr->length == 2)
		nbr = (unsigned char)va_arg(ap, int);
	else if (attr->length == 3)
		nbr = va_arg(ap, unsigned long);
	else if (attr->length == 4)
		nbr = va_arg(ap, unsigned long long);
	else if (attr->conver == 'p')
		nbr = (size_t)va_arg(ap, void *);
	else
		nbr = va_arg(ap, int);
	return (nbr);
}

static char	*put_width(int len, char *str, t_attribute *attr)
{
	char *space;
	char *temp;

	temp = str;
	if (attr->width && attr->flag.min_0 != '-')
	{
		if(len < attr->width)
		{
			if(!(space = ft_strnew(attr->width - len + 1)))
				return (0);
			ft_memset(space, ' ', attr->width - len);
			temp = ft_strjoin(space, str);
			str = temp;
			ft_strdel(&space);
		}
	}
	return (str);
}

static char		*put_precision(char *str, t_attribute *attr)
{
	char *zero;
	int len;
	char *temp;

	len = ft_strlen(str);
	temp = str;
	if(attr->conver == 'o' && attr->flag.sharp)
		len++;
	if (attr->precis)
	{
		if(len < attr->precis)
		{
			if(!(zero = ft_strnew(attr->precis - len + 1)))
				return (0);
			ft_memset(zero, '0', attr->precis - len);
			temp = ft_strjoin(zero, str);
			str = temp;
			ft_strdel(&zero);
		}
	}
	return (str);
}

static char		*put_flag(unsigned long long nbr, t_attribute *attr, int base)
{
	char *str;
	char *sharp;

	sharp = NULL;
	if(attr->flag.sharp)
	{
		if(attr->conver == 'o')
		{
			if(!(sharp = ft_strnew(2)))
				return (0);
			sharp[0] = '0';
		}
		if(attr->conver == 'x' || attr->conver == 'X' || attr->conver == 'p')
		{
			if(!(sharp = ft_strnew(3)))
				return (0);
			sharp[0] = '0';
			if(attr->conver == 'x' || attr->conver == 'p' )
				sharp[1] = 'x';
			else if(attr->conver == 'X')
				sharp[1] = 'X';
		}
	}
	if (!(str = conver_unsigned_to_str(nbr, base, attr)))
		return (NULL);
	str = put_precision(str, attr);
	if(attr->flag.sharp)
	{
			if(!(str = ft_strjoin(sharp, str)))
				return (0);
			ft_strdel(&sharp);
	}
	return(str);
}

int		print_unsigned_nbr(va_list ap, int len, t_attribute *attr, int base)
{
	unsigned long long		nbr;
	char	*str;

	nbr = 0;
	nbr = conver_length(ap, attr);
	str = put_flag(nbr, attr, base);
	len = ft_strlen(str);
	str = put_width(len, str, attr);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

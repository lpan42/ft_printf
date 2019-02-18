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

static uintmax_t conver_length(va_list ap, t_attribute *attr)
{
	uintmax_t nbr;
	nbr = 0;
	if (attr->length == 1)
		nbr = (unsigned short)va_arg(ap, unsigned int);
	else if (attr->length == 2)
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (attr->length == 3)
		nbr = va_arg(ap, unsigned long);
	else if (attr->length == 4)
		nbr = va_arg(ap, unsigned long long);
	else if (attr->length == 6)
		nbr = va_arg(ap, uintmax_t);
	else if (attr->length == 7)
		nbr = va_arg(ap, size_t);
	else if (attr->conver == 'p')
		nbr = (size_t)va_arg(ap, void *);
	else
		nbr = va_arg(ap, unsigned int);
	//printf("nbr: %ju\n", nbr);
	//printf("nbr: ju\n");
	return (nbr);
}

static char	*put_width(int len, char *str, t_attribute *attr)
{
	char *space;
	char *temp;

	temp = str;
	//printf("temp:%s\n", temp);
	//printf("str:%s\n", str);
	if (attr->width)
	{
		//printf("attr->width:%d\n", attr->width);
		if(len < attr->width)
		{
			if(!(space = ft_strnew(attr->width - len + 1)))
				return (0);
			if(attr->flag.min_0 == '0' && !(attr->precis))
				ft_memset(space, '0', attr->width - len);
			else
				ft_memset(space, ' ', attr->width - len);
			//printf("space:%s\n", space);
			//printf("str:%s\n", str);
			if(str)
			{
				if(attr->flag.min_0 != '-')
					str = ft_strjoin(space, temp);
				else
					str = ft_strjoin(temp, space);
				ft_strdel(&space);
				ft_strdel(&temp);
			}
			else
				str = space;
			//printf("str:%s\n", str);
			//printf("temp:%s\n", temp);
			//printf("str_width:%s\n", str);
		}
	//ft_strdel(&temp);
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
			str = ft_strjoin(zero, temp);
			ft_strdel(&zero);
			ft_strdel(&temp);
		}
	}
	return (str);
}

static char		*put_flag(uintmax_t nbr, t_attribute *attr, int base)
{
	char *str;
	char *sharp;
	int len;

	sharp = NULL;
	len = 0;
	//printf("precis: %d\n", attr->precis);
	if (attr->precis == -1 && nbr == 0 && !(attr->conver == 'o' &&
		attr->flag.sharp) && attr->conver != 'p')
		return(NULL);
	if (!(str = conver_unsigned_to_str(nbr, base, attr)))
		return (NULL);
	//printf("str_pre: %s\n", str);
	str = put_precision(str, attr);
	//printf("str_pre: %s\n", str);
	if((attr->flag.sharp && nbr != 0) || (attr->flag.sharp && attr->conver == 'p'))
	{
		if(attr->conver == 'o')
		{
			if(!(sharp = ft_strnew(2)))
				return (0);
			sharp[0] = '0';
		}
		if((attr->conver == 'x' || attr->conver == 'X' || attr->conver == 'p'))
		{
			if(!(sharp = ft_strnew(3)))
				return (0);
			sharp[0] = '0';
			if(attr->conver == 'x' || attr->conver == 'p' )
				sharp[1] = 'x';
			else if(attr->conver == 'X')
				sharp[1] = 'X';
		}
		len = ft_strlen(str) + ft_strlen(sharp);
		if (!(attr->precis) && attr->width && attr->flag.min_0 == '0')
			str = put_width(len, str, attr);
		if(attr->precis == -1 && attr->conver == 'p' && nbr == 0)
			str = sharp;
		else
		{
				if(!(str = ft_strjoin(sharp, str)))
					return (0);
				ft_strdel(&sharp);
		}
	}
	return(str);
}

int		print_unsigned_nbr(va_list ap, int len, t_attribute *attr, int base)
{
	uintmax_t		nbr;
	char	*str;

	nbr = 0;
	nbr = conver_length(ap, attr);
	str = put_flag(nbr, attr, base);
	//printf("str_flag: %s\n", str);
	if (str)
		len = ft_strlen(str);
	//printf("len: %d\n", len);
	str = put_width(len, str, attr);
	//printf("str: %s\n", str);
	if(str)
	{
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
	}
	return (len);
}

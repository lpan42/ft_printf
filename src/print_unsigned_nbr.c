/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:32:55 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:32:57 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static uintmax_t	conver_length(va_list ap, t_attribute *attr)
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
	return (nbr);
}

static char	*put_width_join_space(char *str, char *space, t_attribute *attr)
{
	char *temp;

	temp = str;
	if (attr->flag.min_0 != '-')
		str = ft_strjoin(space, temp);
	else
		str = ft_strjoin(temp, space);
	ft_strdel(&space);
	ft_strdel(&temp);
	return (str);
}

static char	*put_width(int len, char *str, t_attribute *attr)
{
	char	*space;

	if (attr->width)
	{
		if (len < attr->width)
		{
			if (!(space = ft_strnew(attr->width - len + 1)))
				return (0);
			if (attr->flag.min_0 == '0' && !(attr->precis) &&
				attr->flag.plus_spce != ' ')
				ft_memset(space, '0', attr->width - len);
			else if (attr->flag.min_0 == '0' && !(attr->precis) &&
				attr->flag.plus_spce == ' ')
				ft_memset(space, '0', attr->width - len - 1);
			else
				ft_memset(space, ' ', attr->width - len);
			if (str)
				str = put_width_join_space(str, space, attr);
			else
				str = space;
		}
	}
	return (str);
}

static char		*put_precision(char *str, t_attribute *attr)
{
	char	*zero;
	int		len;
	char	*temp;

	len = ft_strlen(str);
	temp = str;
	if (attr->conver == 'o' && attr->flag.sharp)
		len++;
	if (attr->precis)
	{
		if (len < attr->precis)
		{
			if (!(zero = ft_strnew(attr->precis - len + 1)))
				return (0);
			ft_memset(zero, '0', attr->precis - len);
			str = ft_strjoin(zero, temp);
			ft_strdel(&zero);
			ft_strdel(&temp);
		}
	}
	return (str);
}

static char		*reading_sharp(t_attribute *attr)
{
	char *sharp;

	if (attr->conver == 'o')
	{
		if (!(sharp = ft_strnew(2)))
			return (0);
		sharp[0] = '0';
	}
	if ((attr->conver == 'x' || attr->conver == 'X' || attr->conver == 'p'))
	{
		if (!(sharp = ft_strnew(3)))
			return (0);
		sharp[0] = '0';
		if (attr->conver == 'x' || attr->conver == 'p')
			sharp[1] = 'x';
		else if (attr->conver == 'X')
			sharp[1] = 'X';
	}
	return (sharp);
}

static char		*printing_sharp(t_attribute *attr, char *str, uintmax_t nbr,
				char *sharp)
{
	char *temp;

	temp = str;
	if (attr->precis == -1 && attr->conver == 'p' && nbr == 0)
	{
		ft_strdel(&str);
		return (sharp);
	}
	else
	{
		if (!(str = ft_strjoin(sharp, temp)))
			return (0);
		ft_strdel(&sharp);
		ft_strdel(&temp);
	}
	return (str);
}

static char		*put_flag(uintmax_t nbr, t_attribute *attr, int base)
{
	char	*str;
	char	*sharp;
	int		len;

	sharp = NULL;
	str = NULL;
	len = 0;
	if (attr->precis == -1 && nbr == 0 && !(attr->conver == 'o' &&
		attr->flag.sharp) && attr->conver != 'p')
		return (NULL);
	if (!(str = conver_unsigned_to_str(nbr, base, attr)))
		return (NULL);
	str = put_precision(str, attr);
	if ((attr->flag.sharp && nbr != 0) ||
		(attr->flag.sharp && attr->conver == 'p'))
	{
		sharp = reading_sharp(attr);
		len = ft_strlen(str) + ft_strlen(sharp);
		if (!(attr->precis) && attr->width && attr->flag.min_0 == '0')
			str = put_width(len, str, attr);
		str = printing_sharp(attr, str, nbr, sharp);
	}
	return (str);
}

int		print_unsigned_nbr(va_list ap, int len, t_attribute *attr, int base)
{
	uintmax_t		nbr;
	char			*str;

	nbr = 0;
	nbr = conver_length(ap, attr);
	str = put_flag(nbr, attr, base);
	if (str)
		len = ft_strlen(str);
	str = put_width(len, str, attr);
	if (str)
	{
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:17:42 by lpan              #+#    #+#             */
/*   Updated: 2019/01/10 18:17:44 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		get_flag(char f, t_attribute *attr)
{
	if (f == '-' ||  f == '0')
	{
		if(!attr->flag.min_0)
			attr->flag.min_0 = f;
		if(attr->flag.min_0 == '-')
			attr->flag.min_0 = '-';
		return (1);
	}
	if (f == '+' ||  f == ' ')
	{
		if (!attr->flag.plus_spce)
			attr->flag.plus_spce = f;
		if(attr->flag.plus_spce == '+')
			attr->flag.plus_spce = '+';
		return (1);
	}
	if (f == '#')
	{
		attr->flag.sharp = f;
		return(1);
	}
	return (0);
}

static int		get_conversion(char f, t_attribute *attr)
{
	if (f == 'd' || f == 'i' || f == 'o' || f == 'u' || f == 'x' || f == 'X'
		|| f == 'c' || f == 's' || f == 'p' || f == 'f')
	{
		attr->conver = f;
		if(attr->conver == 'p')
			attr->flag.sharp = '#';
		return (1);
	}
	return (0);
}

static int		get_width(char *format, t_attribute *attr)
{
	int	i;
	char *nbr;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	if (!i)
		return (0);
	if(!(nbr = ft_strsub(format, 0, i)))
		return (0);
	else
		attr->width = ft_atoi(nbr);
	ft_strdel(&nbr);
	return (i);
}

static int		get_precision(char *format, t_attribute *attr)
{
	int		i;
	char	*nbr;

	i = 0;
	if (format[0] == '.')
	{
		i = 1;
		while (ft_isdigit(format[i]))
			i++;
		nbr = ft_strsub(format, 1, i);
		if (i == 1)
			return (0);
		else
			attr->precis = ft_atoi(nbr);
		ft_strdel(&nbr);
	}
	return (i);
}

static int		get_length(char *format, t_attribute *attr)
{
	int		i;

	i = 0;
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
	{
		i = 1;
		if (format[0] == 'h')
			format[1] == 'h' ? (attr->length = hh) : (attr->length = h);
		if (format[0] == 'l')
			format[1] == 'l' ? (attr->length = ll) : (attr->length = l);
		if (format[0] == 'L')
			attr->length = L;
		if (attr->length == hh || attr->length == ll)
			i = 2;
	}
	return (i);
}

int		set_attributes(char *format, t_attribute *attr)
{
	int i;
	char *ver;

	i = 0;
	ver = format;

	while(get_flag(*format, attr))
		format++;
	while((i = get_width(format, attr)))
		format += i;
	while((i = get_precision(format, attr)))
		format += i;
	while((i = get_length(format, attr)))
		format += i;
	while(get_conversion(*format, attr))
		format++;
	return (format - ver);
}

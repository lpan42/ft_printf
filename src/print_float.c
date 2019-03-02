/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:25:50 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:31:47 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long double	conver_float_length(va_list ap, t_attribute *attr)
{
	long double nbr;

	nbr = 0;
	if (attr->length == 5)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	return (nbr);
}

static char	*put_width_min(int len, char *str, t_attribute *attr)
{
	char *temp;
	char *space;

	temp = str;
	{
		if (!(space = ft_strnew(attr->width - len + 1)))
			return (0);
		ft_memset(space, ' ', attr->width - len);
		if (attr->flag.min_0 != '-')
			str = ft_strjoin(space, temp);
		else
			str = ft_strjoin(temp, space);
		ft_strdel(&space);
		ft_strdel(&temp);
	}
	return (str);
}

static char	*put_width(int len, char *str, t_attribute *attr)
{
	char *temp;
	char *zero;

	temp = str;
	if (attr->width && attr->flag.min_0 != '-')
	{
		if (len < attr->width)
		{
			if (attr->flag.min_0 == '0')
			{
				if (!(zero = ft_strnew(attr->width - len + 1)))
					return (0);
				ft_memset(zero, '0', attr->width - len);
				str = ft_strjoin(zero, temp);
				ft_strdel(&zero);
				ft_strdel(&temp);
			}
			else
				str = put_width_min(len, str, attr);
		}
	}
	return (str);
}

static char	*put_precision_min(long double nbr, char *str,
				char *aft_decimal)
{
	char	*temp;
	int		bef_decimal;

	bef_decimal = 0;
	while (nbr != 0)
	{
		nbr *= 10;
		if (!(aft_decimal = conver_signed_to_str(nbr)))
			return (NULL);
		if (*aft_decimal <= '3')
		{
			ft_strdel(&aft_decimal);
			break ;
		}
		temp = str;
		if (!(str = ft_strjoin(temp, aft_decimal)))
			return (0);
		bef_decimal = ft_atoi(aft_decimal);
		ft_strdel(&temp);
		ft_strdel(&aft_decimal);
		nbr -= bef_decimal;
	}
	str = rounding_nbr(str, 2);
	str = rounding_nbr_excp(str);
	return (str);
}

static char	*put_precision_norm(long double nbr, char *str,
				char *aft_decimal, int precis)
{
	char	*temp;
	int		bef_decimal;
	int		i;

	i = 0;
	bef_decimal = 0;
	while (i <= precis)
	{
		nbr *= 10;
		if (!(aft_decimal = conver_signed_to_str(nbr)))
			return (NULL);
		temp = str;
		if (!(str = ft_strjoin(temp, aft_decimal)))
			return (0);
		bef_decimal = ft_atoi(aft_decimal);
		ft_strdel(&temp);
		ft_strdel(&aft_decimal);
		nbr -= bef_decimal;
		i++;
	}
	str = rounding_nbr(str, precis);
	return (str);
}

static char	*put_precision(long double nbr, char *str, t_attribute *attr)
{
	char	*aft_decimal;
	char	*temp;
	int		bef_decimal;
	int		i;

	i = 0;
	temp = NULL;
	aft_decimal = NULL;
	bef_decimal = ft_atoi(str);
	nbr -= bef_decimal;
	if (attr->precis == 0)
		attr->precis = 6;
	if (attr->precis == -1)
		str = put_precision_min(nbr, str, aft_decimal);
	else
		str = put_precision_norm(nbr, str, aft_decimal, attr->precis);
	return (str);
}

static char	*add_space_min(int len, int check_min, char *str, t_attribute *attr)
{
	char *space;
	char *temp;

	temp = str;
	if (!(space = ft_strnew(2)))
		return (0);
	if (attr->flag.plus_spce == ' ')
		*space = ' ';
	if (!(check_min == 1 && len <= attr->width) &&
		!(check_min == 1 && !attr->width))
	{
		if (!(str = ft_strjoin(space, temp)))
			return (0);
		ft_strdel(&temp);
	}
	ft_strdel(&space);
	return (str);
}

static char	*add_sign(long double nbr, int check_min, char *str,
			t_attribute *attr)
{
	char *sign;
	char *temp;

	temp = str;
	if (!(sign = ft_strnew(2)))
		return (0);
	if (attr->flag.plus_spce == '+' && nbr >= 0)
		*sign = '+';
	if (check_min == 1)
		*sign = '-';
	if (!(str = ft_strjoin(sign, temp)))
		return (0);
	ft_strdel(&temp);
	ft_strdel(&sign);
	return (str);
}

static char	*put_dot(char *str)
{
	char *dot;
	char *temp;

	temp = NULL;
	if (!(dot = ft_strnew(2)))
		return (0);
	*dot = '.';
	temp = str;
	if (!(str = ft_strjoin(temp, dot)))
		return (0);
	ft_strdel(&temp);
	ft_strdel(&dot);
	return (str);
}

static char	*put_flag(int len, long double nbr, t_attribute *attr)
{
	char	*str;
	int		check_min;

	check_min = 0;
	str = NULL;
	if (nbr < 0)
	{
		check_min = 1;
		nbr = -nbr;
	}
	if (!(str = conver_signed_to_str(nbr)))
		return (NULL);
	str = put_dot(str);
	str = put_precision(nbr, str, attr);
	len = ft_strlen(str);
	if (attr->flag.plus_spce == '+' || attr->flag.min_0 == '-'
		|| check_min == 1)
		len++;
	if (attr->width && attr->flag.min_0 == '0')
		str = put_width(len, str, attr);
	str = add_sign(nbr, check_min, str, attr);
	str = add_space_min(len, check_min, str, attr);
	return (str);
}

int			print_float(va_list ap, int len, t_attribute *attr)
{
	long double		nbr;
	char			*str;

	nbr = 0;
	nbr = conver_float_length(ap, attr);
	str = put_flag(len, nbr, attr);
	len = ft_strlen(str);
	str = put_width(len, str, attr);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

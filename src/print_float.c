/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:25:50 by lpan              #+#    #+#             */
/*   Updated: 2019/01/11 13:25:51 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long double conver_float_length(va_list ap, t_attribute *attr)
{
	long double nbr;

	nbr = 0;
	if (attr->length == 5)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	return (nbr);
}

static char	*put_width(int len, char *str, t_attribute *attr)
{
	char *space;
	char *temp;
	char *zero;

	temp = str;
	if (attr->width && attr->flag.min_0 != '-')
	{
		if(len < attr->width)
		{
			if(attr->flag.min_0 == '0')
			{
				if(!(zero = ft_strnew(attr->width - len + 1)))
				return (0);
				ft_memset(zero, '0', attr->width - len);
				temp = ft_strjoin(zero, str);
				str = temp;
				ft_strdel(&zero);
			}
			else
			{
				if(!(space = ft_strnew(attr->width - len + 1)))
					return (0);
				ft_memset(space, ' ', attr->width - len);
				temp = ft_strjoin(space, str);
				str = temp;
				ft_strdel(&space);
			}
		}
	}
	return (str);
}

static char *rounding_nbr(char *str, int precis)
{
	int i;
	char *temp;
	int count_digit;

	temp = str;
	count_digit = 0;
	while(str[count_digit] != '.')
		count_digit++;
	i = precis + count_digit;
	if (temp[precis + count_digit + 1] > '4')
	{
		if(temp[precis + count_digit] != '9')
			temp[precis + count_digit] += 1;
		else if (temp[precis + count_digit] == '9')
		{
			while(temp[i] == '9')
			{
				temp[i] = '0';
				i--;
			}
			if(temp[i] == '.')
				i--;
			temp[i] += 1;
		}
	}
		if(!(str = ft_strndup(temp, precis + count_digit + 1)))
			return (0);
		ft_strdel(&temp);
		return (str);
}

static char		*put_precision(long double nbr, char *str, t_attribute *attr)
{
	char *aft_decimal;
	int bef_decimal;
	int i;

	i = 0;
	bef_decimal = ft_atoi(str);
	nbr -= bef_decimal;
	if(!(aft_decimal = ft_strnew(2)))
		return (0);
	while(i <= attr->precis)
	{
		nbr *= 10;
		if (!(aft_decimal = conver_signed_to_str(nbr)))
			return (NULL);
		if(!(str = ft_strjoin(str, aft_decimal)))
			return (0);
		bef_decimal = ft_atoi(aft_decimal);
		nbr -= bef_decimal;
		i++;
	}
	str = rounding_nbr(str, attr->precis);
	return (str);
}

static char		*put_flag(long double nbr, t_attribute *attr)
{
	char *str;
	char *sign;
	char *space;
	char *dot;
	int check_min;

	check_min = 0;
	if(!(sign = ft_strnew(2)))
		return (0);
	if(!(space = ft_strnew(2)))
		return (0);
	if(!(dot = ft_strnew(2)))
		return (0);
	if (nbr < 0)
	{
		check_min = 1;
		nbr = -nbr;
	}
	if (!(str = conver_signed_to_str(nbr)))
		return (NULL);
	*dot = '.';
	if(!(str = ft_strjoin(str, dot)))
		return (0);
	str = put_precision(nbr, str, attr);
	if (attr->flag.plus_spce == '+' && nbr >= 0)
		*sign = '+';
	if (check_min == 1)
		*sign = '-';
	if (attr->flag.plus_spce == ' ')
		*space = ' ';
	if(!(str = ft_strjoin(sign, str)))
		return (0);
	if(!(str = ft_strjoin(space, str)))
		return (0);
	ft_strdel(&sign);
	ft_strdel(&space);
	ft_strdel(&dot);
	return(str);
}

int		print_float(va_list ap, int len, t_attribute *attr)
{
		long double	nbr;
		char	*str;

		nbr = 0;
		nbr = conver_float_length(ap, attr);
		str = put_flag(nbr, attr);
		len = ft_strlen(str);
		str = put_width(len, str, attr);
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
		return (len);
}

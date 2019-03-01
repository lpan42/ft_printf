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
				str = ft_strjoin(zero, temp);
				ft_strdel(&zero);
			}
			else
			{
				if(!(space = ft_strnew(attr->width - len + 1)))
					return (0);
				ft_memset(space, ' ', attr->width - len);
				if(attr->flag.min_0 != '-')
					str = ft_strjoin(space, temp);
				else
					str = ft_strjoin(temp, space);
				ft_strdel(&space);
			}
			ft_strdel(&temp);
		}
	}
	return (str);
}

static char		*put_precision(long double nbr, char *str, t_attribute *attr)
{
	char *aft_decimal;
	char *temp;
	int bef_decimal;
	int i;

	i = 0;
	temp = NULL; ////////
	aft_decimal = NULL;
	bef_decimal = ft_atoi(str);
	nbr -= bef_decimal;
	if(attr->precis == 0)
		attr->precis = 6;
	//printf("attr->precis:%d\n", attr->precis);
	if(attr->precis == -1)
	{
		while(nbr != 0)
		{
			nbr *= 10;
			//printf("nbr:%Lf\n", nbr);
			if (!(aft_decimal = conver_signed_to_str(nbr)))
				return (NULL);
			if(*aft_decimal <= '3')
			{
				ft_strdel(&aft_decimal);
				break;
			}
			temp = str;
			if(!(str = ft_strjoin(temp, aft_decimal)))
				return (0);
			//printf("\naft_decimal: %s\n", aft_decimal);
			bef_decimal = ft_atoi(aft_decimal);
			//printf("bef_decimal:%d\n", bef_decimal);
			ft_strdel(&temp);
			ft_strdel(&aft_decimal);////////
			nbr -= bef_decimal;
		}
		//printf("\naft_decimal: %s\n", aft_decimal);
		//printf("\ntemp: %s\n", temp);
		//printf("\nstr: %s\n", str);
		str = rounding_nbr(str, 2);
		//printf("str: %s\n", str);
		str = rounding_nbr_excp(str);
	}
	else
	{
		while(i <= attr->precis)
		{
			nbr *= 10;
			if (!(aft_decimal = conver_signed_to_str(nbr)))
				return (NULL);
			temp = str;
			if(!(str = ft_strjoin(temp, aft_decimal)))
				return (0);
			bef_decimal = ft_atoi(aft_decimal);
			ft_strdel(&temp);
			ft_strdel(&aft_decimal);////////
			nbr -= bef_decimal;
			i++;
		}
	//	printf("\nstr: %s\n", str);
		str = rounding_nbr(str, attr->precis);
	}
	//printf("str: %s\n", str);
	return (str);
}

static char		*put_flag(int len, long double nbr, t_attribute *attr)
{
	char *str;
	char *sign;
	char *space;
	char *dot;
	char *temp;
	int check_min;

	check_min = 0;
	temp = NULL;
	str = NULL;
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
	temp = str;
	if(!(str = ft_strjoin(temp, dot)))
		return (0);
	ft_strdel(&temp);
	str = put_precision(nbr, str, attr);
	if (attr->flag.plus_spce == '+' && nbr >= 0)
		*sign = '+';
	if (check_min == 1)
		*sign = '-';
	if (attr->flag.plus_spce == ' ')
		*space = ' ';
	len = ft_strlen(str);
	if(attr->flag.plus_spce == '+' || attr->flag.min_0 == '-' || check_min == 1)
		len++;
	if (attr->width && attr->flag.min_0 == '0')
		str = put_width(len, str, attr);
	temp = str;
	if(!(str = ft_strjoin(sign, temp)))
		return (0);
	ft_strdel(&temp);
	//printf("\nattr->width: %d\n",attr->width);
	//printf("check_min: %d\n",check_min);
	if(!(check_min == 1 && len <= attr->width) && !(check_min == 1 && !attr->width))
	{
		temp = str;
		if(!(str = ft_strjoin(space, temp)))
			return (0);
		ft_strdel(&temp);
	}
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
		str = put_flag(len, nbr, attr);
		len = ft_strlen(str);
		str = put_width(len, str, attr);
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
		return (len);
}

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
				if(attr->flag.min_0 != '-')
					temp = ft_strjoin(space, str);
				else
					temp = ft_strjoin(str, space);
				str = temp;
				ft_strdel(&space);
			}
		}
	}
	return (str);
}

static char	*check_9(int count_digit,char *str, int precis)
{
	char *temp;
	int i;

	i = 0;
	temp = NULL;
//printf("\nstr: %s\n", str);
//999.99987
//012345678
	if(str[0] == '9')
	{
		while(i < count_digit + precis)
		{
			if(str[i] == '9')
				i++;
			else if (str[i] == '.')
				i++;
			else
				break;
		}
		if(str[i] != '9')
		 	i--;
		// printf("i: %d\n", i);
		// printf("count_digit: %d\n", count_digit);
		// printf("c+p: %d\n", count_digit + precis);
		if(i == count_digit + precis)
		{
			if(!(temp = ft_strnew((count_digit + precis + 1 + 1) + 1)))
				return(NULL);
			ft_memset(temp, '0', count_digit + precis + 2);
			temp[0] = '1';
			temp[count_digit + 1] = '.';
		//	printf("temp: %s\n", temp);
		}
	}
	else
	{
		i = 1;
		while(i < count_digit + precis)
		{
			if(str[i] == '9')
				i++;
			else if (str[i] == '.')
				i++;
			else
				break;
		}
		if(str[i] != '9')
		 	i--;
		// printf("i: %d\n", i);
		// printf("count_digit: %d\n", count_digit);
		// printf("c+p: %d\n", count_digit + precis);
		if(i == count_digit + precis)
		{
			if(!(temp = ft_strnew((count_digit + precis + 1) + 1)))
				return(NULL);
			ft_memset(temp, '0', count_digit + precis + 1);
			temp[0] = str[0] + 1;
			temp[count_digit] = '.';
		}
	}
	return (temp);
}
static char *rounding_nbr(char *str, int precis)
{
	int i;
	char *temp;
	int count_digit;

	temp = NULL;
	count_digit = 0;
	//printf("\nstr: %s\n", str);
	while(str[count_digit] != '.')
		count_digit++;
	temp = check_9(count_digit, str, precis);
	//printf("temp: %s\n", temp);
	if(temp)
		return (temp);
	temp = str;
	//printf("temp : %s\n", temp);
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

static char *rounding_nbr_excp(char *str)
{
	int i;
	char *temp;
	int count_digit;

	temp = str;
	count_digit = 0;
	//printf("\nstr: %s\n", str);
	while(str[count_digit] != '.')
		count_digit++;
	//printf("count_digit: %d\n", count_digit);
	i = count_digit;
	if (temp[count_digit + 1] > '4')
	{
		if(temp[count_digit + 1] != '9')
			temp[count_digit - 1] += 1;
		else if (temp[count_digit + 1] == '9')
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
		if(!(str = ft_strndup(temp, count_digit)))
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
	if(attr->precis == 0)
		attr->precis = 6;
	//printf("attr->precis:%d\n", attr->precis);
	//printf("nbr:%Lf\n", nbr);
	if(attr->precis == -1)
	{
		while(nbr != 0)
		{
			nbr *= 10;
			if (!(aft_decimal = conver_signed_to_str(nbr)))
				return (NULL);
			if(*aft_decimal <= '3')
				break;
			if(!(str = ft_strjoin(str, aft_decimal)))
				return (0);
			bef_decimal = ft_atoi(aft_decimal);
			nbr -= bef_decimal;
		}
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
			if(!(str = ft_strjoin(str, aft_decimal)))
				return (0);
			bef_decimal = ft_atoi(aft_decimal);
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
	len = ft_strlen(str);
	if(attr->flag.plus_spce == '+' || attr->flag.min_0 == '-' || check_min == 1)
		len++;
	if (attr->flag.plus_spce == ' ')
		*space = ' ';
	if (attr->width && attr->flag.min_0 == '0')
		str = put_width(len, str, attr);
	if(!(str = ft_strjoin(sign, str)))
		return (0);
	//printf("\nattr->width: %d\n",attr->width);
	//printf("check_min: %d\n",check_min);
	if(!(check_min == 1 && len <= attr->width) && !(check_min == 1 && !attr->width))
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
		str = put_flag(len, nbr, attr);
		len = ft_strlen(str);
		str = put_width(len, str, attr);
		ft_putstr(str);
		len = ft_strlen(str);
		ft_strdel(&str);
		return (len);
}

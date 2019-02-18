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

static intmax_t conver_length(va_list ap, t_attribute *attr)
{
	intmax_t nbr;

	nbr = 0;
	if (attr->length == 1)
		nbr = (short)va_arg(ap, int);
	else if (attr->length == 2)
		nbr = (signed char)va_arg(ap, int);
	else if (attr->length == 3)
		nbr = va_arg(ap, long);
	else if (attr->length == 4)
		nbr = va_arg(ap, long long);
	else if (attr->length == 6)
		nbr = va_arg(ap, intmax_t);
	else if (attr->length == 7)
		nbr = va_arg(ap, size_t);
	else
		nbr = va_arg(ap, int);
	//printf("nbr: %ju\n", nbr);
	return (nbr);
}

static char	*put_width(int len, char *str, t_attribute *attr)
{
	char *space;
	char *temp;

	temp = str;
	if (attr->width)
	{
		if(len < attr->width)
		{
			if(!(space = ft_strnew(attr->width - len + 1)))
				return (0);
			if(attr->flag.min_0 == '0' && !(attr->precis) &&
				attr->flag.plus_spce != ' ')
				ft_memset(space, '0', attr->width - len);
			else if(attr->flag.min_0 == '0' && !(attr->precis) &&
				attr->flag.plus_spce == ' ')
				ft_memset(space, '0', attr->width - len - 1);
			else
				ft_memset(space, ' ', attr->width - len);
			if(str)
			{
				if(attr->flag.min_0 != '-')
					temp = ft_strjoin(space, str);
				else
					temp = ft_strjoin(str, space);
				str = temp;
				ft_strdel(&space);
			}
			else
				str = space;
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

static char		*put_flag(intmax_t nbr, t_attribute *attr)
{
	char *str;
	char *sign;
	char *space;
	int check_min;
	int len;

	check_min = 0;
	len = 0;
	// printf("attr->precis: %d\n", attr->precis);
	// printf("nbr: %ju\n", nbr);
	if (attr->precis == -1 && nbr == 0)
		return(NULL);
	if(!(sign = ft_strnew(2)))
		return (0);
	if(!(space = ft_strnew(2)))
		return (0);
	if (nbr < 0)
	{
		check_min = 1;
		nbr = -nbr;
	}
	//printf("nbr: %ju\n", nbr);
	if (!(str = conver_signed_to_str(nbr)))
		return (NULL);
	//printf("str: %s\n", str);
	//printf("check_min: %d\n", check_min);
	str = put_precision(str, attr);
	if (attr->flag.plus_spce == '+' && nbr >= 0)
		*sign = '+';
	if (check_min == 1)
		*sign = '-';
	len = ft_strlen(str);
	if(attr->flag.plus_spce == '+' || attr->flag.min_0 == '-' || check_min == 1)
		len++;
	if (attr->flag.plus_spce == ' ')
		*space = ' ';
	if (!(attr->precis) && attr->width && attr->flag.min_0 == '0')
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
	return(str);
}

int		print_signed_nbr(va_list ap, int len, t_attribute *attr)
{
	signed long long		nbr;
	char	*str;

	nbr = 0;
	nbr = conver_length(ap, attr);
	//printf("nbr: %ju\n", nbr);
	str = put_flag(nbr, attr);
	//printf("str: %s\n", str);
	if (str)
		len = ft_strlen(str);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:32:30 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:32:33 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static intmax_t		conver_length(va_list ap, t_attribute *attr)
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

static char		*add_sign(char *str, int check_min, t_attribute *attr,
				intmax_t nbr)
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

static char		*add_space(char *str, t_attribute *attr)
{
	char *space;
	char *temp;

	temp = str;
	if (!(space = ft_strnew(2)))
		return (0);
	if (attr->flag.plus_spce == ' ')
		*space = ' ';
	if (!(str = ft_strjoin(space, temp)))
		return (0);
	ft_strdel(&temp);
	ft_strdel(&space);
	return (str);
}

static int		count_len(char *str, t_attribute *attr, int check_min)
{
	int len;

	len = ft_strlen(str);
	if (attr->flag.plus_spce == '+' || attr->flag.min_0 == '-' ||
		check_min == 1)
		len++;
	return (len);
}

static char		*put_flag(intmax_t nbr, t_attribute *attr)
{
	char	*str;
	int		check_min;
	int		len;

	len = 0;
	check_min = 0;
	if (attr->precis == -1 && nbr == 0)
		return (NULL);
	if (nbr < 0)
	{
		check_min = 1;
		nbr = -nbr;
	}
	if (!(str = conver_signed_to_str(nbr)))
		return (NULL);
	str = put_precision(str, attr);
	len = count_len(str, attr, check_min);
	if (!(attr->precis) && attr->width && attr->flag.min_0 == '0')
		str = put_width(len, str, attr);
	str = add_sign(str, check_min, attr, nbr);
	if (!(check_min == 1 && len <= attr->width) &&
		!(check_min == 1 && !attr->width))
		str = add_space(str, attr);
	return (str);
}

int		print_signed_nbr(va_list ap, int len, t_attribute *attr)
{
	signed long long		nbr;
	char					*str;

	nbr = 0;
	nbr = conver_length(ap, attr);
	str = put_flag(nbr, attr);
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

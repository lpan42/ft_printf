/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_unsigned_to_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:31:24 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:31:31 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"
#include "libft.h"

static int	count_unsigned_digit(uintmax_t n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / base;
	}
	return (count);
}

char	*conver_unsigned_to_str(uintmax_t n, int base, t_attribute *attr)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = count_unsigned_digit(n, base);
	if(!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n != 0)
	{
		if (n % base < 10)
			str[--len] = n % base + 48;
		else
		{
			if(attr->conver == 'X')
				str[--len] = n % base + 55;
			if(attr->conver == 'x' || attr->conver == 'p')
				str[--len] = n % base + 87;
		}
		n = n / base;
	}
	return (str);
}

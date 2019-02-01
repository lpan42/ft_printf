/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:53:35 by lpan              #+#    #+#             */
/*   Updated: 2018/11/15 16:53:36 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		count_signed_digit(signed long long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void		positive_nbr(int len, signed long long n, char *str)
{
	while (n != 0)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
}

char			*conver_signed_to_str(signed long long n)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = count_signed_digit(n);
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	positive_nbr(len, n, str);
	return (str);
}

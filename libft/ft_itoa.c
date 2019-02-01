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

#include "libft.h"

static void		ft_positive_nbr(int len, int n, char *str)
{
	while (n != 0)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_digit_count(n);
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	ft_positive_nbr(len, n, str);
	return (str);
}

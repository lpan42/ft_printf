/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conver_signed_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:30:22 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:30:43 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		count_signed_digit(intmax_t n)
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

static void		positive_nbr(int len, intmax_t n, char *str)
{
	while (n != 0)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
}

char			*conver_signed_to_str(intmax_t n)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = count_signed_digit(n);
	if (n < 0)
		len++;
	if(!(str = malloc(sizeof(char) * (len + 1))))
		return (0);////////
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -9223372036854775807LL - 1LL)
	{
		ft_strdel(&str);
		return (ft_strdup("9223372036854775808"));
	}
	//printf("nbr: %jd\n", n);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	positive_nbr(len, n, str);
	return (str);
}

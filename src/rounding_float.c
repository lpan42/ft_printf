/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:33:04 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:33:06 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*check_9_add_onedigit(int count_digit, char *str, int precis)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (i < count_digit + precis)
	{
		if (str[i] == '9')
			i++;
		else if (str[i] == '.')
			i++;
		else
			break ;
	}
	if (str[i] != '9')
		i--;
	if (i == count_digit + precis)
	{
		if (!(temp = ft_strnew((count_digit + precis + 1 + 1) + 1)))
			return (NULL);
		ft_memset(temp, '0', count_digit + precis + 2);
		temp[0] = '1';
		temp[count_digit + 1] = '.';
	}
	return (temp);
}

char	*check_9_norm(int count_digit, char *str, int precis)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 1;
	while (i < count_digit + precis)
	{
		if (str[i] == '9')
			i++;
		else if (str[i] == '.')
			i++;
		else
			break ;
	}
	if (str[i] != '9')
		i--;
	if (i == count_digit + precis)
	{
		if (!(temp = ft_strnew((count_digit + precis + 1) + 1)))
			return (NULL);
		ft_memset(temp, '0', count_digit + precis + 1);
		temp[0] = str[0] + 1;
		temp[count_digit] = '.';
	}
	return (temp);
}

char	*check_9(int count_digit, char *str, int precis)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (str[0] == '9')
		temp = check_9_add_onedigit(count_digit, str, precis);
	else
		temp = check_9_norm(count_digit, str, precis);
	return (temp);
}

char	*bigger_than_4(int i, char *temp, int precis, int count_digit)
{
	if (temp[precis + count_digit] != '9')
		temp[precis + count_digit] += 1;
	else if (temp[precis + count_digit] == '9')
	{
		while (temp[i] == '9')
		{
			temp[i] = '0';
			i--;
		}
		if (temp[i] == '.')
			i--;
		temp[i] += 1;
	}
	return (temp);
}

char	*rounding_nbr(char *str, int precis)
{
	int		i;
	char	*temp;
	int		count_digit;

	temp = NULL;
	count_digit = 0;
	while (str[count_digit] != '.')
		count_digit++;
	temp = check_9(count_digit, str, precis);
	if (temp)
	{
		ft_strdel(&str);
		return (temp);
	}
	temp = str;
	i = precis + count_digit;
	if (temp[precis + count_digit + 1] > '4')
		bigger_than_4(i, temp, precis, count_digit);
	if (!(str = ft_strndup(temp, precis + count_digit + 1)))
		return (0);
	ft_strdel(&temp);
	return (str);
}

char	*bigger_than_4_excp(int i, char *temp, int count_digit)
{
	if (temp[count_digit + 1] != '9')
		temp[count_digit - 1] += 1;
	else if (temp[count_digit + 1] == '9')
	{
		while (temp[i] == '9')
		{
			temp[i] = '0';
			i--;
		}
		if (temp[i] == '.')
			i--;
		temp[i] += 1;
	}
	return (temp);
}

char	*rounding_nbr_excp(char *str)
{
	int		i;
	char	*temp;
	int		count_digit;

	temp = str;
	count_digit = 0;
	while (str[count_digit] != '.')
		count_digit++;
	i = count_digit;
	if (temp[count_digit + 1] > '4')
		bigger_than_4_excp(i, temp, count_digit);
	if (!(str = ft_strndup(temp, count_digit)))
		return (0);
	ft_strdel(&temp);
	return (str);
}

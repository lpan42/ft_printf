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

static int print_0_space(int len, t_attribute *attr)
{
	while (attr->width > len)
	{
		if (attr->flag.min_0 == '0' && attr->width)
			ft_putchar('0');
		if (attr->flag.min_0 != '0' && attr->width)
			ft_putchar(' ');
		len += 1;
	}
	return (len);
}

int print_no_specifier(char c, int len, t_attribute *attr)
{
	if(c)
		len = sizeof(char);
	if (!(attr->flag.min_0 == '-'))
		len = print_0_space(len, attr);
	if(c)
		ft_putchar(c);
	if (attr->flag.min_0 == '-')
		len = print_0_space(len, attr);
	//printf("len : %d\n", len);
	return (len);
}

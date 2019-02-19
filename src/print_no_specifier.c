/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:32:04 by lpan              #+#    #+#             */
/*   Updated: 2019/02/19 14:32:07 by lpan             ###   ########.fr       */
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

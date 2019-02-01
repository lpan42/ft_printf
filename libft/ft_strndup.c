/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:29:06 by lpan              #+#    #+#             */
/*   Updated: 2018/11/21 17:29:08 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		size;
	char	*dup;

	size = ft_strlen(s1);
	dup = (char*)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, n);
	dup[n] = '\0';
	return (dup);
}

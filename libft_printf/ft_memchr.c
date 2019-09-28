/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:21:35 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/05 10:11:49 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *dest, int symb, size_t n)
{
	size_t			i;
	unsigned char	s;

	s = (unsigned char)symb;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)dest)[i] == s)
			return ((void *)dest + i);
		i++;
	}
	return (0);
}

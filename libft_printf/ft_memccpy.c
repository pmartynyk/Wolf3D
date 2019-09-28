/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:02:36 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/05 10:06:35 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int symb, size_t len)
{
	size_t			i;
	unsigned char	s;

	s = (unsigned char)symb;
	i = 0;
	while (i < len)
	{
		if (((unsigned char*)src)[i] == s)
		{
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
			return (dest + i + 1);
		}
		else
			((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (0);
}

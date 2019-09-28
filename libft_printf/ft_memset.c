/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:50:21 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/12 16:20:32 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int symb, size_t len)
{
	size_t			i;
	unsigned char	s;

	s = (unsigned char)symb;
	i = 0;
	while (i < len)
	{
		((unsigned char*)dest)[i] = s;
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 09:51:38 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/30 14:31:53 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (src[i] == '\0' && i + j < len)
	{
		dest[i + j] = '\0';
		j++;
	}
	return (dest);
}

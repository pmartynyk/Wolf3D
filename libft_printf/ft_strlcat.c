/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:13:52 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/03 11:13:30 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t i;
	size_t len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	if (len == 0)
		return (ft_strlen(src));
	if (len - 1 < ft_strlen(dest))
		return (ft_strlen(src) + len);
	while (len_dest + i < len - 1 && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + ft_strlen(src));
}

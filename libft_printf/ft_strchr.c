/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:17:41 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/03 11:17:07 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int to_find)
{
	int i;

	i = 0;
	if (to_find == '\0')
		return ((char *)src + ft_strlen(src));
	while (src[i])
	{
		if (src[i] == to_find)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

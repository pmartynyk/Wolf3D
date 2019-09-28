/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:37:33 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/03 11:17:30 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int to_find)
{
	int i;

	i = ft_strlen(src);
	if (to_find == '\0')
		return ((char *)src + ft_strlen(src));
	while (i >= 0)
	{
		if (src[i] == to_find)
			return ((char *)&src[i]);
		i--;
	}
	return (0);
}

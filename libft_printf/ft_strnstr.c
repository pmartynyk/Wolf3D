/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:03:44 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/03 11:18:48 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t len_to_find;

	i = 0;
	j = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)src);
	while (i < len && src[i])
	{
		if (src[i] == to_find[j] && j <= len_to_find)
		{
			j++;
			if (j == len_to_find)
				return ((char *)&src[i - j + 1]);
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:56:28 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/03 11:18:11 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int i;
	int j;
	int len_to_find;

	i = 0;
	j = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)src);
	while (src[i])
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:40:59 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/30 16:47:01 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;
	char	*res;

	if (s1 != 0 && s2 != 0)
	{
		i = 0;
		j = 0;
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (res == 0)
			return (0);
		while (s1[i])
			res[j++] = s1[i++];
		i = 0;
		while (s2[i])
			res[j++] = s2[i++];
		res[j] = '\0';
		return (res);
	}
	return (0);
}

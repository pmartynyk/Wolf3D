/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:26:24 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/30 13:56:30 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*out;
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (src[k] != '\0')
		k++;
	out = (char*)malloc(sizeof(char) * (k + 1));
	if (out == 0)
		return (0);
	while (i <= k)
	{
		out[i] = src[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

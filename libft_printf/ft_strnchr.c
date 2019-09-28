/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:07:21 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/25 12:09:12 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnchr(char *src, int cnt)
{
	int i;

	i = 0;
	if (cnt == 0)
		return (src);
	while (src[i])
	{
		if (i == cnt)
			return ((char *)&src[i]);
		i++;
	}
	return (0);
}

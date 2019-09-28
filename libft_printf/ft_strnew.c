/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:02:45 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/30 16:37:38 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (0);
	while (i <= size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:36:25 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 17:16:23 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (size));
	if (res == 0)
		return (0);
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

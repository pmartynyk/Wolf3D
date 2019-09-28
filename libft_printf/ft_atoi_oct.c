/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:05:47 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/07 12:05:49 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	result_oct(const char *s)
{
	unsigned long long int	res;
	int						i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] >= 48 && s[i] < 58)
		{
			res = res * 8 + (s[i] - '0');
		}
		i++;
	}
	return (res);
}

unsigned long long int	ft_atoi_oct(const char *src)
{
	int						i;
	unsigned long long int	res;

	res = 0;
	i = 0;
	while (src[i] == '\n' || src[i] == '\t'
			|| src[i] == '\v' || src[i] == '\f'
			|| src[i] == '\r' || src[i] == ' ')
		i++;
	res = result_oct(src);
	return (res);
}

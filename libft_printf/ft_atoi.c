/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:48:46 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 15:58:20 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	result(const char *s, int i, int sign)
{
	int res;
	int cnt;

	cnt = 0;
	res = 0;
	while (s[i])
	{
		if (cnt < 10)
		{
			if (s[i] >= 48 && s[i] < 58)
			{
				res = res * 10 + s[i] - '0';
				cnt = res == 0 ? cnt : cnt + 1;
			}
			else
				return (res);
			i++;
		}
		else
			return (sign == -1 ? 0 : -1);
	}
	return (res);
}

int			ft_atoi(const char *src)
{
	int	i;
	int	sign;
	int res;

	res = 0;
	sign = 1;
	i = 0;
	while (src[i] == '\n' || src[i] == '\t'
			|| src[i] == '\v' || src[i] == '\f'
			|| src[i] == '\r' || src[i] == ' ')
		i++;
	if (src[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (src[i] == '+')
		i++;
	res = result(src, i, sign);
	return (res * sign);
}

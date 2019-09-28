/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:55:45 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/31 12:55:47 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_power(int nb, int power)
{
	int result;

	result = 1;
	if (power > 0)
	{
		while (power)
		{
			result = result * nb;
			power--;
		}
	}
	else if (power < 0)
	{
		result = 0;
	}
	return (result);
}

static	int		check_and_convert_to_int(char c, int base)
{
	int res;

	if (c >= '0' && c <= '9')
		res = c - 48;
	else if (c >= 'a' && c <= 'f')
		res = c - 97 + 10;
	else if (c >= 'A' && c <= 'F')
		res = c - 65 + 10;
	else
		res = -1;
	if (res < base && res != -1)
		return (res);
	else
		return (-1);
}

static	int		count_length(char *src, int base)
{
	int length;

	length = 0;
	while (src[length])
	{
		if (check_and_convert_to_int(src[length], base) == -1)
			break ;
		length++;
	}
	return (length);
}

int				ft_atoi_base(char *src, int base)
{
	int i;
	int length;
	int res;

	i = 0;
	res = 0;
	if (base == 10)
		return (ft_atoi(src));
	while (src[i] == '\n' || src[i] == '\t'
		|| src[i] == '\v' || src[i] == '\f'
		|| src[i] == '\r' || src[i] == ' ')
		i++;
	length = count_length(src, base) - 1;
	while (src[i] && length >= 0 &&
		check_and_convert_to_int(src[i], base) != -1)
	{
		res += check_and_convert_to_int(src[i], base) * ft_power(base, length);
		i++;
		length--;
	}
	return (res);
}

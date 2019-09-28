/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:39:10 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/11 13:39:11 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_unsigned_intlen(unsigned long long int n)
{
	int len;

	len = 0;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

int				ft_signed_charlen(signed char n)
{
	int len;

	len = 0;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

int				ft_unsigned_charlen(unsigned char n)
{
	int len;

	len = 0;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

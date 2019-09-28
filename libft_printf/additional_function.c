/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additonal_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:40:19 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/29 15:40:20 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(long long int n)
{
	int len;

	len = 0;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

int		ft_unsigned_intlen_oct(unsigned long long int n)
{
	int len;

	len = 0;
	while (n / 8 > 0)
	{
		len++;
		n /= 8;
	}
	return (len + 1);
}

int		ft_unsigned_charlen_oct(unsigned char n)
{
	int len;

	len = 0;
	while (n / 8 > 0)
	{
		len++;
		n /= 8;
	}
	return (len + 1);
}

void	*my_bzero(t_conv_template *temp)
{
	temp->flag_zero = 0;
	temp->flag_minus = 0;
	temp->flag_plus = 0;
	temp->flag_space = 0;
	temp->flag_sharp = 0;
	temp->field_wigth = -1;
	temp->presicion = -1;
	temp->length = no;
	temp->type = '0';
	return (0);
}

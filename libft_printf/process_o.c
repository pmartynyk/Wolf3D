/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:55:35 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/23 11:57:23 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_o_minus_flags(t_conv_template temp, unsigned long long int num)
{
	int len_num;

	len_num = ft_unsigned_intlen_oct(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		(temp.flag_sharp && num != 0 ? ft_putchar('0') : 0);
		ft_putonbr(num);
		return ;
	}
	if (temp.flag_sharp)
	{
		temp.presicion--;
		temp.field_wigth--;
	}
	if (len_num < temp.presicion)
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	(temp.flag_sharp ? ft_putchar('0') : 0);
	ft_putonbr(num);
	while (--temp.field_wigth + 1 - len_num > 0)
		ft_putchar(' ');
}

void	process_o_else(t_conv_template temp, unsigned long long int num)
{
	int len_num;

	len_num = ft_unsigned_intlen_oct(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		process_o_else_add(temp, num);
		return ;
	}
	if (temp.flag_sharp)
	{
		temp.presicion--;
		temp.field_wigth--;
	}
	if (len_num > temp.presicion)
		while (--temp.field_wigth + 1 > len_num)
			ft_putchar((temp.presicion <= -1 && temp.flag_zero == 1 ?
				'0' : ' '));
	else
		while (--temp.field_wigth + 1 > temp.presicion)
			ft_putchar(' ');
	while (--temp.presicion + 1 > len_num)
		ft_putchar('0');
	(temp.flag_sharp ? ft_putchar('0') : 0);
	(num == 0 && temp.presicion == -1 ? ft_putchar(' ') : ft_putonbr(num));
}

void	process_o_else_add(t_conv_template temp, unsigned long long int num)
{
	if (num == 0 && temp.presicion == 0)
		(temp.flag_sharp ? ft_putchar('0') : 0);
	else
	{
		(temp.flag_sharp && num != 0 ? ft_putchar('0') : 0);
		ft_putonbr(num);
	}
}

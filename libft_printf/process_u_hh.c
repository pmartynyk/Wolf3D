/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u_minus_hh.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:37:33 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/11 14:37:34 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_u_plus_minus_flags_hh(t_conv_template temp, unsigned char num)
{
	int len_num;

	len_num = ft_unsigned_charlen(num);
	(temp.type == 'x' && temp.flag_sharp ? ft_putstr("0x") : 0);
	(temp.type == 'X' && temp.flag_sharp ? ft_putstr("0X") : 0);
	(temp.type == 'p' ? ft_putstr("0x") : 0);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		ft_putunbr(num);
		return ;
	}
	if (len_num < temp.presicion)
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	ft_putuhhnbr(num);
	while (--temp.field_wigth + 1 - len_num > 0)
		ft_putchar(' ');
}

void	process_u_plus_flags_hh(t_conv_template temp, unsigned char num)
{
	int len_num;

	len_num = ft_unsigned_charlen(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		ft_putuhhnbr(num);
		return ;
	}
	if (len_num > temp.presicion)
		while (--temp.field_wigth + 1 > len_num)
			ft_putchar(' ');
	else
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar(' ');
			temp.field_wigth--;
		}
	if (temp.presicion == -1 && temp.flag_zero == 1)
		while (--temp.field_wigth + 1 > len_num)
			ft_putchar('0');
	else if (temp.presicion > len_num)
		while (--temp.presicion + 1 > len_num)
			ft_putchar(' ');
	ft_putuhhnbr(num);
}

void	process_u_else_hh(t_conv_template temp, unsigned char num)
{
	int len_num;

	len_num = ft_unsigned_charlen(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		if (num == 0 && temp.presicion == 0)
			;
		else
			ft_putuhhnbr(num);
		return ;
	}
	if (len_num > temp.presicion)
		while (--temp.field_wigth + 1 > len_num)
			ft_putchar((temp.presicion == -1 && temp.flag_zero == 1 ?
				'0' : ' '));
	else
		while (--temp.field_wigth + 1 > temp.presicion)
			ft_putchar(' ');
	while (--temp.presicion + 1 > len_num)
		ft_putchar('0');
	(num == 0 && temp.presicion == -1 ? ft_putchar(' ') : ft_putuhhnbr(num));
}

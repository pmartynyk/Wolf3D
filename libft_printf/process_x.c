/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x_minus_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:42:13 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/07 14:42:14 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_x_minus_flags(t_conv_template temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	if (temp.flag_sharp)
	{
		print_x_prefix(&temp, num);
		if (temp.field_wigth > len_num)
			temp.field_wigth = temp.field_wigth - 2;
	}
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		ft_putstr(num);
		return ;
	}
	if (len_num < temp.presicion)
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	ft_putstr(num);
	while (--temp.field_wigth + 1 - len_num > 0)
		ft_putchar(' ');
}

void	process_x_else(t_conv_template temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		if (temp.flag_sharp)
			print_x_prefix(&temp, num);
		if (ft_atoi(num) == 0 && temp.presicion == 0)
			;
		else
			ft_putstr(num);
		return ;
	}
	if (temp.flag_sharp)
		print_x_sharp(&temp, num);
	else
		print_x_not_sharp(&temp, num);
	while (--temp.presicion + 1 > len_num)
		ft_putchar('0');
	(ft_atoi(num) == 0 && temp.presicion == -1 ?
		ft_putchar(' ') : ft_putstr(num));
}

void	print_x_sharp(t_conv_template *temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	temp->field_wigth = temp->field_wigth - 2;
	(temp->flag_zero == 0 ? print_x_not_sharp(temp, num) : 0);
	if (len_num > temp->presicion && temp->presicion == -1)
	{
		print_x_prefix(temp, num);
		while (--temp->field_wigth + 1 > len_num)
			ft_putchar('0');
	}
	else
	{
		while (--temp->field_wigth + 1 > (len_num > temp->presicion ?
			len_num : temp->presicion))
			ft_putchar(' ');
		print_x_prefix(temp, num);
	}
}

void	print_x_not_sharp(t_conv_template *temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	if (len_num > temp->presicion)
		while (--temp->field_wigth + 1 > len_num)
			ft_putchar((temp->presicion <= -1 && temp->flag_zero == 1 ?
				'0' : ' '));
	else
		while (--temp->field_wigth + 1 > temp->presicion)
			ft_putchar(' ');
}

void	print_x_prefix(t_conv_template *temp, char *num)
{
	(temp->type == 'x' && ft_atoi_base(num, 16) != 0 ? ft_putstr("0x") : 0);
	(temp->type == 'X' && ft_atoi_base(num, 16) != 0 ? ft_putstr("0X") : 0);
}

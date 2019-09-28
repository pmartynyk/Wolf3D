/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_else_hh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:01:24 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/12 17:01:25 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d_else_hh(t_conv_template temp, char num)
{
	int len_num;

	len_num = ft_signed_charlen((num > 0 ? num : -num));
	(num >= 0 && temp.flag_space == 1 ? ft_putchar(' ') : 0);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		if (num == 0 && temp.presicion == 0)
			return ;
		(num < 0 ? ft_putchar('-') : 0);
		ft_putdhhnbr(num);
		return ;
	}
	print_else_hh(&temp, len_num, num);
	if (len_num < temp.presicion)
	{
		while (--temp.presicion + 1 > len_num)
			ft_putchar('0');
		temp.presicion++;
	}
	(num == 0 && temp.presicion == 0 ? ft_putchar(' ') : 0);
	(num == 0 && temp.presicion == 0 ? 0 : ft_putdhhnbr(num));
}

void	print_else_hh(t_conv_template *temp, int len_num, char num)
{
	if (len_num > temp->presicion && temp->flag_zero == 1)
	{
		(num < 0 ? ft_putchar('-') : 0);
		while (--temp->field_wigth + 1 > len_num + (num < 0 ? 1 : 0))
			(temp->presicion == -1 ? ft_putchar('0') : ft_putchar(' '));
	}
	else if (len_num > temp->presicion)
	{
		while (--temp->field_wigth + 1 > len_num + (num < 0 ? 1 : 0))
			ft_putchar(' ');
		(num < 0 ? ft_putchar('-') : 0);
	}
	else
	{
		while (--temp->field_wigth + 1 > temp->presicion + (num < 0 ? 1 : 0))
			ft_putchar(' ');
		(num < 0 ? ft_putchar('-') : 0);
	}
}

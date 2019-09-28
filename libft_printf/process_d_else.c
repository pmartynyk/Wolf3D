/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_else.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:36:10 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/04 16:36:12 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d_else(t_conv_template temp, long long int num)
{
	int len_num;

	len_num = ft_intlen(num);
	if (num >= 0 && temp.flag_space == 1)
	{
		ft_putchar(' ');
		temp.field_wigth--;
	}
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		if (num == 0 && temp.presicion == 0)
			return ;
		(num < 0 ? ft_putchar('-') : 0);
		(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
		return ;
	}
	print_else(&temp, len_num, num);
	(num == 0 && temp.presicion == 0 ? ft_putchar(' ') : 0);
	if (num == 0 && temp.presicion == 0)
		;
	else
		(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
}

void	print_else(t_conv_template *temp, int len_num, long long int num)
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
	if (len_num < temp->presicion)
	{
		while (--temp->presicion + 1 > len_num)
			ft_putchar('0');
		temp->presicion++;
	}
}

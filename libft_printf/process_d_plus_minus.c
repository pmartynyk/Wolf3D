/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:20:08 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/03 12:20:10 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d_plus_minus_flags(t_conv_template temp, long long int num)
{
	if (temp.flag_plus && !temp.flag_minus)
		process_d_plus(temp, num);
	else if (!temp.flag_plus && temp.flag_minus)
		process_d_minus(temp, num);
	else if (temp.flag_plus && temp.flag_minus)
		process_d_plus_and_minus(temp, num);
}

void	process_d_plus(t_conv_template temp, long long int num)
{
	int		len_num;

	len_num = ft_intlen(num);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(num >= 0 ? ft_putchar('+') : ft_putchar('-'));
		(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
		return ;
	}
	(temp.flag_zero ? print_zero_sign(num) : 0);
	if (len_num < temp.presicion)
		while (--temp.field_wigth > temp.presicion)
			ft_putchar(' ');
	else
		while (--temp.field_wigth > len_num)
			(temp.flag_zero ? ft_putchar('0') : ft_putchar(' '));
	(temp.flag_zero == 0 ? print_zero_sign(num) : 0);
	if (temp.presicion > len_num)
		while (--temp.presicion + 1 > len_num)
			ft_putchar('0');
	(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
}

void	process_d_minus(t_conv_template temp, long long int num)
{
	int len_num;

	len_num = ft_intlen(num);
	print_minus_prefix(&temp, num);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
		return ;
	}
	if (temp.presicion > len_num)
	{
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	}
	(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
	while (--temp.field_wigth + 1 > len_num)
		ft_putchar(' ');
}

void	process_d_plus_and_minus(t_conv_template temp, long long int num)
{
	int		len_num;

	len_num = ft_intlen(num);
	(num >= 0 ? ft_putchar('+') : ft_putchar('-'));
	temp.field_wigth--;
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
		return ;
	}
	if (temp.field_wigth > temp.presicion)
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	(num >= 0 ? ft_putlnbr(num) : ft_putlnbr(-num));
	while (--temp.field_wigth + 1 > len_num)
		ft_putchar(' ');
}

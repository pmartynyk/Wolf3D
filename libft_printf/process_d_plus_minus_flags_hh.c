/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_plus_minus_flags_hh.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:46:01 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/12 16:46:03 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d_plus_minus_flags_hh(t_conv_template temp, char num)
{
	if (temp.flag_plus && !temp.flag_minus)
		process_d_plus_hh(temp, num);
	else if (!temp.flag_plus && temp.flag_minus)
		process_d_minus_hh(temp, num);
	else if (temp.flag_plus && temp.flag_minus)
		process_d_plus_and_minus_hh(temp, num);
}

void	process_d_plus_hh(t_conv_template temp, char num)
{
	int		len_num;

	len_num = ft_unsigned_charlen(num);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(num >= 0 ? ft_putchar('+') : ft_putchar('-'));
		(num >= 0 ? ft_putuhhnbr(num) : ft_putuhhnbr(-num));
		return ;
	}
	if (len_num < temp.presicion)
		while (--temp.field_wigth > temp.presicion)
			ft_putchar(' ');
	else
		while (--temp.field_wigth > len_num)
			ft_putchar(' ');
	(num >= 0 ? ft_putchar('+') : ft_putchar('-'));
	if (temp.presicion > len_num)
		while (--temp.presicion + 1 > len_num)
			ft_putchar('0');
	(num >= 0 ? ft_putuhhnbr(num) : ft_putuhhnbr(-num));
}

void	process_d_minus_hh(t_conv_template temp, char num)
{
	int len_num;

	len_num = ft_signed_charlen(num);
	print_minus_prefix(&temp, num);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(num >= 0 ? ft_putuhhnbr(num) : ft_putuhhnbr(-num));
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
	(num >= 0 ? ft_putuhhnbr(num) : ft_putuhhnbr(-num));
	while (--temp.field_wigth + 1 > len_num)
		ft_putchar(' ');
}

void	process_d_plus_and_minus_hh(t_conv_template temp, char num)
{
	int		len_num;

	len_num = ft_signed_charlen(num);
	(num >= 0 ? ft_putchar('+') : ft_putchar('-'));
	temp.field_wigth--;
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(num >= 0 ? ft_putuhhnbr(num) : ft_putuhhnbr(-num));
		return ;
	}
	if (temp.field_wigth < temp.presicion)
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	(num >= 0 ? ft_putuhhnbr(num) : ft_putuhhnbr(-num));
	while (--temp.field_wigth + 1 > len_num)
		ft_putchar(' ');
}

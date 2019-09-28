/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_o_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:12:07 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/13 13:12:10 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_o_no_length(t_conv_template temp, va_list ap)
{
	unsigned int		num;

	num = va_arg(ap, unsigned int);
	num = ft_dec_to_oct(num);
	if (temp.flag_minus)
		process_o_minus_flags(temp, num);
	else
		process_o_else(temp, num);
}

void	process_o_l_length(t_conv_template temp, va_list ap)
{
	unsigned long		l_num;

	l_num = va_arg(ap, unsigned long int);
	l_num = ft_dec_to_oct(l_num);
	if (temp.flag_minus)
		process_o_minus_flags(temp, l_num);
	else
		process_o_else(temp, l_num);
}

void	process_o_ll_length(t_conv_template temp, va_list ap)
{
	unsigned long long	ll_num;

	ll_num = va_arg(ap, unsigned long long int);
	ll_num = ft_dec_to_oct(ll_num);
	if (temp.flag_minus)
		process_o_minus_flags(temp, ll_num);
	else
		process_o_else(temp, ll_num);
}

void	process_o_h_length(t_conv_template temp, va_list ap)
{
	unsigned short		h_num;

	h_num = va_arg(ap, int);
	h_num = ft_dec_to_oct(h_num);
	if (temp.flag_minus)
		process_o_minus_flags(temp, h_num);
	else
		process_o_else(temp, h_num);
}

void	process_o_hh_length(t_conv_template temp, va_list ap)
{
	unsigned char	hh_num;

	hh_num = va_arg(ap, int);
	hh_num = ft_dec_to_oct(hh_num);
	if (temp.flag_minus)
		process_o_minus_flags_hh(temp, hh_num);
	else
		process_o_else_hh(temp, hh_num);
}

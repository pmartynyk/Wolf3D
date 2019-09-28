/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:05:34 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/13 13:05:36 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_u_no_length(t_conv_template temp, va_list ap)
{
	unsigned int		num;

	num = va_arg(ap, unsigned int);
	if ((temp.flag_minus && temp.flag_plus) || temp.flag_minus)
		process_u_plus_minus_flags(temp, num);
	else if (!temp.flag_minus && temp.flag_plus)
		process_u_plus_flags(temp, num);
	else
		process_u_else(temp, num);
}

void	process_u_l_length(t_conv_template temp, va_list ap)
{
	unsigned long		l_num;

	l_num = va_arg(ap, unsigned long int);
	if ((temp.flag_minus && temp.flag_plus) || temp.flag_minus)
		process_u_plus_minus_flags(temp, l_num);
	else if (!temp.flag_minus && temp.flag_plus)
		process_u_plus_flags(temp, l_num);
	else
		process_u_else(temp, l_num);
}

void	process_u_ll_length(t_conv_template temp, va_list ap)
{
	unsigned long long	ll_num;

	ll_num = va_arg(ap, unsigned long long int);
	if ((temp.flag_minus && temp.flag_plus) || temp.flag_minus)
		process_u_plus_minus_flags(temp, ll_num);
	else if (!temp.flag_minus && temp.flag_plus)
		process_u_plus_flags(temp, ll_num);
	else
		process_u_else(temp, ll_num);
}

void	process_u_h_length(t_conv_template temp, va_list ap)
{
	unsigned short		h_num;

	h_num = va_arg(ap, int);
	if ((temp.flag_minus && temp.flag_plus) || temp.flag_minus)
		process_u_plus_minus_flags(temp, h_num);
	else if (!temp.flag_minus && temp.flag_plus)
		process_u_plus_flags(temp, h_num);
	else
		process_u_else(temp, h_num);
}

void	process_u_hh_length(t_conv_template temp, va_list ap)
{
	unsigned char		hh_num;

	hh_num = va_arg(ap, int);
	if ((temp.flag_minus && temp.flag_plus) || temp.flag_minus)
		process_u_plus_minus_flags_hh(temp, hh_num);
	else if (!temp.flag_minus && temp.flag_plus)
		process_u_plus_flags_hh(temp, hh_num);
	else
		process_u_else_hh(temp, hh_num);
}

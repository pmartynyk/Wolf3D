/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:19:11 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/12 17:19:13 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d_no_length(t_conv_template temp, va_list ap)
{
	int		num;

	num = va_arg(ap, int);
	if (temp.flag_minus || temp.flag_plus)
		process_d_plus_minus_flags(temp, num);
	else
		process_d_else(temp, num);
}

void	process_d_l_length(t_conv_template temp, va_list ap)
{
	long int	l_num;

	l_num = va_arg(ap, long int);
	if (temp.flag_minus || temp.flag_plus)
		process_d_plus_minus_flags(temp, (long long)l_num);
	else
		process_d_else(temp, (long long)l_num);
}

void	process_d_ll_length(t_conv_template temp, va_list ap)
{
	long int	ll_num;

	ll_num = va_arg(ap, long long int);
	if (temp.flag_minus || temp.flag_plus)
		process_d_plus_minus_flags(temp, ll_num);
	else
		process_d_else(temp, ll_num);
}

void	process_d_h_length(t_conv_template temp, va_list ap)
{
	short int	h_num;

	h_num = va_arg(ap, int);
	if (temp.flag_minus || temp.flag_plus)
		process_d_plus_minus_flags(temp, h_num);
	else
		process_d_else(temp, h_num);
}

void	process_d_hh_length(t_conv_template temp, va_list ap)
{
	char	hh_num;

	hh_num = va_arg(ap, int);
	if (temp.flag_minus || temp.flag_plus)
		process_d_plus_minus_flags_hh(temp, hh_num);
	else
		process_d_else_hh(temp, hh_num);
}

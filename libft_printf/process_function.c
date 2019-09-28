/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:25:34 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/25 10:06:39 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d(t_conv_template temp, va_list ap)
{
	if (temp.length == no)
		process_d_no_length(temp, ap);
	else if (temp.length == l)
		process_d_l_length(temp, ap);
	else if (temp.length == ll)
		process_d_ll_length(temp, ap);
	else if (temp.length == h)
		process_d_h_length(temp, ap);
	else if (temp.length == hh)
		process_d_hh_length(temp, ap);
}

void	process_u(t_conv_template temp, va_list ap)
{
	if (temp.length == no)
		process_u_no_length(temp, ap);
	else if (temp.length == l)
		process_u_l_length(temp, ap);
	else if (temp.length == ll)
		process_u_ll_length(temp, ap);
	else if (temp.length == h)
		process_u_h_length(temp, ap);
	else if (temp.length == hh)
		process_u_hh_length(temp, ap);
}

void	process_o(t_conv_template temp, va_list ap)
{
	if (temp.length == no)
		process_o_no_length(temp, ap);
	else if (temp.length == l)
		process_o_l_length(temp, ap);
	else if (temp.length == ll)
		process_o_ll_length(temp, ap);
	else if (temp.length == h)
		process_o_h_length(temp, ap);
	else if (temp.length == hh)
		process_o_hh_length(temp, ap);
}

void	process_x(t_conv_template temp, va_list ap)
{
	if (temp.length == no)
		process_x_no_length(temp, ap);
	else if (temp.length == l)
		process_x_l_length(temp, ap);
	else if (temp.length == ll)
		process_x_ll_length(temp, ap);
	else if (temp.length == h)
		process_x_h_length(temp, ap);
	else if (temp.length == hh)
		process_x_hh_length(temp, ap);
}

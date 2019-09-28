/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:29:47 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/30 10:29:48 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_f(t_conv_template temp, va_list ap)
{
	if (temp.length == no)
		process_f_no_length(temp, ap);
	else if (temp.length == l)
		process_f_l_length(temp, ap);
	else if (temp.length == L)
		process_f_l_length(temp, ap);
}

void	process_f_no_length(t_conv_template temp, va_list ap)
{
	double	num;
	char	*str;

	num = va_arg(ap, double);
	str = convert_f(num, temp);
	if (temp.flag_minus || temp.flag_plus)
		process_f_plus_minus_flags(temp, str);
	else
		process_f_else(temp, str);
	free(str);
}

void	process_f_l_length(t_conv_template temp, va_list ap)
{
	long double	num;
	char		*str;

	num = va_arg(ap, long double);
	str = convert_f(num, temp);
	if (temp.flag_minus || temp.flag_plus)
		process_f_plus_minus_flags(temp, str);
	else
		process_f_else(temp, str);
	free(str);
}

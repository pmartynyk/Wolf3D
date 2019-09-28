/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_function_csp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:08:45 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/13 14:08:46 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_c(t_conv_template temp, va_list ap)
{
	char	val;

	val = va_arg(ap, int);
	if (temp.flag_zero)
		process_c_zero(temp, val);
	else if (temp.flag_minus)
		process_c_minus(temp, val);
	else
		process_c_else(temp, val);
}

void	process_s(t_conv_template temp, va_list ap)
{
	char	*val;

	val = va_arg(ap, char *);
	if (val == NULL)
	{
		val = "(null)";
	}
	if (temp.flag_minus)
		process_s_minus(temp, val);
	else
		process_s_else(temp, val);
}

void	process_p(t_conv_template temp, va_list ap)
{
	long long int			num;
	char					*hex;

	num = va_arg(ap, long long int);
	hex = ft_itoa_base(num, 16, temp.type);
	if (temp.flag_minus)
		process_p_minus(temp, hex);
	else
		process_p_else(temp, hex);
	free(hex);
}

void	process_interest(t_conv_template temp, va_list ap)
{
	char	val;

	(void)ap;
	val = '%';
	if (temp.flag_minus)
		process_interest_minus(temp, val);
	else
		process_interest_else(temp, val);
}

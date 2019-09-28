/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:17:41 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/13 13:17:44 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_x_no_length(t_conv_template temp, va_list ap)
{
	unsigned int	num;
	char			*hex;

	num = va_arg(ap, unsigned int);
	hex = ft_itoa_base(num, 16, temp.type);
	if (temp.flag_minus)
		process_x_minus_flags(temp, hex);
	else
		process_x_else(temp, hex);
	free(hex);
}

void	process_x_l_length(t_conv_template temp, va_list ap)
{
	unsigned long int	num;
	char				*hex;

	num = va_arg(ap, unsigned long int);
	hex = ft_itoa_base(num, 16, temp.type);
	if (temp.flag_minus)
		process_x_minus_flags(temp, hex);
	else
		process_x_else(temp, hex);
	free(hex);
}

void	process_x_ll_length(t_conv_template temp, va_list ap)
{
	unsigned long long int	num;
	char					*hex;

	num = va_arg(ap, unsigned long long int);
	hex = ft_itoa_base(num, 16, temp.type);
	if (temp.flag_minus)
		process_x_minus_flags(temp, hex);
	else
		process_x_else(temp, hex);
	free(hex);
}

void	process_x_h_length(t_conv_template temp, va_list ap)
{
	unsigned short int	num;
	char				*hex;

	num = va_arg(ap, int);
	hex = ft_itoa_base(num, 16, temp.type);
	if (temp.flag_minus)
		process_x_minus_flags(temp, hex);
	else
		process_x_else(temp, hex);
	free(hex);
}

void	process_x_hh_length(t_conv_template temp, va_list ap)
{
	unsigned char	num;
	char			*hex;

	num = va_arg(ap, int);
	hex = ft_itoa_base(num, 16, temp.type);
	if (temp.flag_minus)
		process_x_minus_flags(temp, hex);
	else
		process_x_else(temp, hex);
	free(hex);
}

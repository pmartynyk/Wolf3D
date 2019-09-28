/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:38:50 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/29 15:38:51 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_conversion(char *param, va_list ap)
{
	t_conv_template	temp;
	char			*conv;

	conv = ft_strchr(param, '%');
	if (*param == '\0')
		return (0);
	if (conv == NULL)
	{
		ft_putstr(param);
		return (0);
	}
	else if (conv > param)
	{
		ft_putnstr(param, conv - param);
		return (print_conversion(conv, ap));
	}
	else
	{
		my_bzero(&temp);
		if (fill_conv_struct(&param, temp, ap) == -1)
			return (-1);
		else
			return (print_conversion(param, ap));
	}
}

int		fill_conv_struct(char **conv, t_conv_template temp, va_list ap)
{
	if (**conv == '%')
		(*conv)++;
	if (check_conv_flag(&conv, &temp) == NULL)
		return (-1);
	if (check_field_wigth(&conv, &temp) == NULL)
		return (-1);
	if (check_presicion(&conv, &temp) == NULL)
		return (-1);
	if (check_length(&conv, &temp) == NULL)
		return (-1);
	if (check_type(&conv, &temp, ap) == NULL)
		return (-1);
	process_conversion(temp, ap);
	return (0);
}

void	process_conversion(t_conv_template temp, va_list ap)
{
	if (temp.type == 'd' || temp.type == 'i')
		process_d(temp, ap);
	else if (temp.type == 'u')
		process_u(temp, ap);
	else if (temp.type == 'o')
		process_o(temp, ap);
	else if (temp.type == 'x' || temp.type == 'X')
		process_x(temp, ap);
	else if (temp.type == 'c')
		process_c(temp, ap);
	else if (temp.type == 's')
		process_s(temp, ap);
	else if (temp.type == 'p')
		process_p(temp, ap);
	else if (temp.type == '%')
		process_interest(temp, ap);
	else if (temp.type == 'f')
		process_f(temp, ap);
	my_bzero(&temp);
}

int		check_str(char conv)
{
	if (conv == ' '
		|| conv == '+' || conv == '-' || conv == '0'
		|| conv == '#' || conv == 'l' || conv == 'L'
		|| conv == 'h' || conv == '.')
		return (0);
	else
		return (-1);
}

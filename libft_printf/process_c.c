/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:29:22 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/13 14:29:24 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_c_zero(t_conv_template temp, char val)
{
	while (temp.field_wigth > 1)
	{
		ft_putchar('0');
		temp.field_wigth--;
	}
	ft_putchar(val);
}

void	process_c_minus(t_conv_template temp, char val)
{
	ft_putchar(val);
	while (temp.field_wigth > 1)
	{
		ft_putchar(' ');
		temp.field_wigth--;
	}
}

void	process_c_else(t_conv_template temp, char val)
{
	while (temp.field_wigth > 1)
	{
		ft_putchar(' ');
		temp.field_wigth--;
	}
	ft_putchar(val);
}

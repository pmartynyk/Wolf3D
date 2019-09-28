/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 10:06:44 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/25 10:06:45 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_f_plus_minus_flags(t_conv_template temp, char *num)
{
	if (temp.flag_plus && !temp.flag_minus)
		process_f_plus(temp, num);
	else if (!temp.flag_plus && temp.flag_minus)
		process_f_minus(temp, num);
	else if (temp.flag_plus && temp.flag_minus)
		process_f_plus_and_minus(temp, num);
}

void	process_f_plus(t_conv_template temp, char *num)
{
	int		len_num;

	len_num = ft_strlen(num);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(ft_atoi(num) >= 0 ? ft_putchar('+') : 0);
		ft_putstr(num);
		return ;
	}
	if (temp.flag_zero == 0)
	{
		while (--temp.field_wigth + (ft_atoi(num) < 0 ? 1 : 0) > len_num)
			ft_putchar(' ');
		(ft_atoi(num) >= 0 ? ft_putchar('+') : 0);
		ft_putstr(num);
	}
	else if (temp.flag_zero == 1)
	{
		(ft_atoi(num) >= 0 ? ft_putchar('+') : ft_putchar('-'));
		while (--temp.field_wigth + (ft_atoi(num) < 0 ? 1 : 0) > len_num)
			ft_putchar('0');
		(ft_atoi(num) >= 0 ? ft_putstr(num) : ft_putstr(ft_strnchr(num, 1)));
	}
}

void	process_f_minus(t_conv_template temp, char *num)
{
	int		len_num;

	len_num = ft_strlen(num);
	if (ft_atoi(num) >= 0 && temp.flag_space)
	{
		ft_putchar(' ');
		temp.field_wigth--;
	}
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		ft_putstr(num);
		return ;
	}
	ft_putstr(num);
	while (--temp.field_wigth + 1 > len_num)
		ft_putchar(' ');
}

void	process_f_plus_and_minus(t_conv_template temp, char *num)
{
	int		len_num;

	len_num = ft_strlen(num);
	if (ft_atoi(num) >= 0 && temp.flag_space)
	{
		ft_putchar(' ');
		temp.field_wigth--;
	}
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		(ft_atoi(num) >= 0 ? ft_putchar('+') : 0);
		ft_putstr(num);
		return ;
	}
	(ft_atoi(num) >= 0 ? ft_putchar('+') : 0);
	ft_putstr(num);
	while (--temp.field_wigth + (ft_atoi(num) < 0 ? 1 : 0) > len_num)
		ft_putchar(' ');
}

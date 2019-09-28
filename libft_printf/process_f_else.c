/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f_else.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:50:04 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/25 11:52:18 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_f_else(t_conv_template temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	(ft_atoi(num) >= 0 && temp.flag_space == 1 ? ft_putchar(' ') : 0);
	if (len_num >= temp.field_wigth && len_num >= temp.presicion)
	{
		if (ft_atoi(num) == 0 && temp.presicion == 0)
		{
			ft_putstr("0");
			return ;
		}
		ft_putstr(num);
		return ;
	}
	print_else_f(&temp, len_num, num);
}

void	print_else_f(t_conv_template *temp, int len_num, char *num)
{
	if (temp->flag_zero == 0)
	{
		while (--temp->field_wigth + 1 > len_num)
			ft_putchar(' ');
		ft_putstr(num);
	}
	else if (temp->flag_zero == 1)
	{
		(ft_atoi(num) < 0 ? ft_putchar('-') : 0);
		while (--temp->field_wigth + 1 > len_num)
			ft_putchar('0');
		(ft_atoi(num) >= 0 ? ft_putstr(num) : ft_putstr(ft_strnchr(num, 1)));
	}
}

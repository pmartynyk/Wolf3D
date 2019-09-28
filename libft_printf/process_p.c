/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:01:59 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/24 11:02:00 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_p_minus(t_conv_template temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		ft_putstr("0x");
		ft_putstr(num);
		return ;
	}
	if (len_num < temp.presicion)
		while (--temp.presicion + 1 > len_num)
		{
			ft_putchar('0');
			temp.field_wigth--;
		}
	ft_putstr("0x");
	ft_putstr(num);
	while (--temp.field_wigth - 1 - len_num > 0)
		ft_putchar(' ');
}

void	process_p_else(t_conv_template temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	if (len_num > temp.field_wigth && len_num > temp.presicion)
	{
		ft_putstr("0x");
		if (ft_atoi(num) == 0 && temp.presicion == 0)
			;
		else
			ft_putstr(num);
		return ;
	}
	if (len_num > temp.presicion)
		print_p_presicion(&temp, num);
	else
	{
		while (--temp.field_wigth - 1 > temp.presicion)
			ft_putchar(' ');
		ft_putstr("0x");
	}
	while (--temp.presicion + 1 > len_num)
		ft_putchar('0');
	(ft_atoi(num) == 0 && temp.presicion == -1 ? 0 : ft_putstr(num));
}

void	print_p_presicion(t_conv_template *temp, char *num)
{
	int len_num;

	len_num = ft_strlen(num);
	if (temp->presicion >= 0)
	{
		while (--temp->field_wigth - 1 > (ft_atoi(num) != 0 ? len_num : 0))
			ft_putchar(temp->flag_zero == 1 ? '0' : ' ');
		ft_putstr("0x");
	}
	else
	{
		while (--temp->field_wigth - 1 > (ft_atoi(num) != 0 ? len_num : 1))
			ft_putchar(temp->flag_zero == 1 ? '0' : ' ');
		ft_putstr("0x");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:21:48 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/13 15:27:31 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_s_minus(t_conv_template temp, char *val)
{
	int pres;
	int i;
	int len;

	len = ft_strlen(val);
	i = 0;
	pres = temp.presicion == -1 ? 0 : temp.presicion;
	while ((i < (pres > 0 ? pres : len)) && val[i])
	{
		ft_putchar(val[i]);
		i++;
		temp.field_wigth--;
	}
	while (temp.field_wigth > 0)
	{
		ft_putchar(' ');
		temp.field_wigth--;
	}
}

void	process_s_else(t_conv_template temp, char *val)
{
	int pres;
	int i;
	int len;

	len = ft_strlen(val);
	i = 0;
	if (len == 0)
		pres = 0;
	else if (len < temp.presicion)
		pres = len;
	else
		pres = temp.presicion == -1 ? 0 : temp.presicion;
	while ((temp.field_wigth - (pres > 0 ? pres : len)) > 0)
	{
		if (temp.flag_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		temp.field_wigth--;
	}
	while ((i < (pres > 0 ? pres : len)) && val[i])
	{
		ft_putchar(val[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:32:52 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/26 11:32:54 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *param, ...)
{
	va_list	ap;
	int		res;

	g_len = 0;
	va_start(ap, param);
	res = print_conversion(param, ap);
	va_end(ap);
	return (g_len);
}

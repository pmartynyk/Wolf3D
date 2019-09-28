/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_interest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:17:53 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/24 12:22:34 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_interest_minus(t_conv_template temp, char val)
{
	ft_putchar(val);
	while (--temp.field_wigth + 1 > 1)
		ft_putchar(' ');
}

void	process_interest_else(t_conv_template temp, char val)
{
	while (--temp.field_wigth + 1 > 1)
		ft_putchar(' ');
	ft_putchar(val);
}

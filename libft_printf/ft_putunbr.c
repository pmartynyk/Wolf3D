/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:06:42 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/06 16:06:44 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned long long int n)
{
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

void	ft_putuhhnbr(unsigned char n)
{
	if (n > 9)
	{
		ft_putuhhnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

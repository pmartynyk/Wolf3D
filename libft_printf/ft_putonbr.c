/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putonbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:03:18 by pmartyny          #+#    #+#             */
/*   Updated: 2019/01/16 11:03:20 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putonbr(unsigned long long int n)
{
	if (n > 7)
	{
		ft_putonbr(n / 8);
		ft_putchar(n % 8 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

void	ft_putohhnbr(unsigned char n)
{
	if (n > 7)
	{
		ft_putohhnbr(n / 8);
		ft_putchar(n % 8 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

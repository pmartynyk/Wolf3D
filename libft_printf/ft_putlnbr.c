/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:35:19 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/10 15:35:20 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlnbr(long long int n)
{
	if (n < 0)
	{
		ft_putlnbr(-(n / 10));
		ft_putchar(-(n % 10) + 48);
	}
	else if (n > 9)
	{
		ft_putlnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

void	ft_putdhhnbr(char n)
{
	if (n < 0)
	{
		(n / 10 != 0 ? ft_putdhhnbr(-(n / 10)) : 0);
		ft_putchar(-(n % 10) + 48);
	}
	else if (n > 9)
	{
		ft_putdhhnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
	{
		ft_putchar(n + 48);
	}
}

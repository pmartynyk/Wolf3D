/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:38:22 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/06 16:38:24 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*n_pos(unsigned long long int n, int base, char type)
{
	int							len;
	unsigned long long int		n_len;
	char						*res;
	char						*base_num;

	base_num = (type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	n_len = n;
	len = 1;
	while (n_len / base > 0)
	{
		len++;
		n_len /= base;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = '\0';
	while (--len >= 0)
	{
		res[len] = base_num[n % base];
		n /= base;
	}
	return (res);
}

char	*ft_itoa_base(unsigned long long int n, int base, char type)
{
	char	*res;

	if (n > 0)
		res = n_pos(n, base, type);
	else
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}

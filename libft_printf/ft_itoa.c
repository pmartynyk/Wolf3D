/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:27:42 by pmartyny          #+#    #+#             */
/*   Updated: 2018/10/31 13:45:30 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_pos(int n)
{
	int		len;
	int		n_len;
	char	*res;

	n_len = n;
	len = 1;
	while (n_len / 10 > 0)
	{
		len++;
		n_len /= 10;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = '\0';
	while (--len >= 0)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static char	*n_neg(int n)
{
	int		len;
	int		n_len;
	char	*res;

	n_len = n;
	len = 1;
	while (n_len / 10 < 0)
	{
		len++;
		n_len /= 10;
	}
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (res == 0)
		return (0);
	res[0] = '-';
	res[len + 1] = '\0';
	while (len > 0)
	{
		res[len] = n % 10 * -1 + '0';
		n /= 10;
		len--;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;

	if (n > 0)
		res = n_pos(n);
	else if (n < 0)
		res = n_neg(n);
	else
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_additional_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:27:36 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/05 13:28:53 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_minus_prefix(t_conv_template *temp, int num)
{
	if (num >= 0 && temp->flag_space)
	{
		ft_putchar(' ');
		temp->field_wigth--;
	}
	else if (num < 0)
	{
		ft_putchar('-');
		temp->field_wigth--;
	}
}

char	*convert_f(long double num, t_conv_template temp)
{
	char	*res;
	int		len;
	int		i;
	int		pres;

	len = 0;
	i = 0;
	res = ft_memalloc(1);
	(num < 0 ? res = ft_strjoin(res, "-") : 0);
	(num < 0 ? num *= -1 : 0);
	while (num > 1)
	{
		num /= 10;
		len++;
	}
	(len == 0 ? res = ft_strjoin(res, "0") : 0);
	while (len-- > 0)
		push_res(&res, &num);
	(temp.presicion != 0 || temp.flag_sharp ? res = ft_strjoin(res, ".") : 0);
	pres = (temp.presicion != -1 ? temp.presicion : 6);
	while (i++ < pres)
		push_res(&res, &num);
	return (res);
}

void	push_res(char **res, long double *num)
{
	*num *= 10;
	*res = ft_strjoin(*res, ft_itoa((int)(*num)));
	*num = *num - (int)*num;
}

void	print_zero_sign(int num)
{
	(num >= 0 ? ft_putchar('+') : ft_putchar('-'));
}

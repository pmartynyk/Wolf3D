/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:29:59 by pmartyny          #+#    #+#             */
/*   Updated: 2018/12/06 16:30:02 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int			ft_dec_to_oct(unsigned long long int num)
{
	char					*res_oct;
	unsigned long long int	res;

	res_oct = ft_itoa_base(num, 8, 'o');
	res = ft_atoi_oct(res_oct);
	free(res_oct);
	return (res);
}

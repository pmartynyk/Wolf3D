/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:49:45 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/29 15:49:46 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_conv_flag(char ***conv, t_conv_template *temp)
{
	if (***conv == '#' || ***conv == '+' || ***conv == '-' || ***conv == '0'
		|| ***conv == ' ')
	{
		if (***conv == '#')
			temp->flag_sharp = 1;
		else if (***conv == '+')
			temp->flag_plus = 1;
		else if (***conv == '-')
			temp->flag_minus = 1;
		else if (***conv == '0')
			temp->flag_zero = 1;
		else if (***conv == ' ')
			temp->flag_space = 1;
		(**conv)++;
		if (temp->flag_minus == 1)
			temp->flag_zero = 0;
		if (temp->flag_plus == 1)
			temp->flag_space = 0;
		return (check_conv_flag(conv, temp));
	}
	else
		return (**conv);
}

char	*check_field_wigth(char ***conv, t_conv_template *temp)
{
	int n;

	n = 0;
	if (ft_isdigit(***conv))
	{
		temp->field_wigth = ft_atoi(**conv);
		n = ft_intlen(temp->field_wigth);
	}
	while (n > 0)
	{
		(**conv)++;
		n--;
	}
	return (**conv);
}

char	*check_presicion(char ***conv, t_conv_template *temp)
{
	int n;

	n = 0;
	if (***conv == '.')
	{
		(**conv)++;
		temp->presicion = 0;
		if (temp->field_wigth == -1)
			temp->field_wigth = 0;
	}
	if (ft_isdigit(***conv))
	{
		temp->presicion = ft_atoi(**conv);
		n = ft_intlen(temp->presicion);
	}
	while (n > 0)
	{
		(**conv)++;
		n--;
	}
	return (**conv);
}

char	*check_length(char ***conv, t_conv_template *temp)
{
	if (***conv == 'l' && *(**conv + 1) == 'l')
		temp->length = ll;
	else if (***conv == 'l')
		temp->length = l;
	else if (***conv == 'h' && *(**conv + 1) == 'h')
		temp->length = hh;
	else if (***conv == 'h')
		temp->length = h;
	else if (***conv == 'L')
		temp->length = L;
	else
		temp->length = no;
	if (temp->length == h || temp->length == l || temp->length == L)
		(**conv)++;
	else if (temp->length == hh || temp->length == ll)
		(**conv) += 2;
	return (**conv);
}

char	*check_type(char ***conv, t_conv_template *temp, va_list ap)
{
	if (***conv == 'd' || ***conv == 'i' || ***conv == 'o'
		|| ***conv == 'u' || ***conv == 'x' || ***conv == 'X'
		|| ***conv == 'f' || ***conv == 'c' || ***conv == 's'
		|| ***conv == 'p' || ***conv == '%' || ***conv == '\0')
	{
		temp->type = ***conv;
		(**conv)++;
		return (**conv);
	}
	if (temp->type == '0')
	{
		if (check_str(***conv) == -1)
		{
			(**conv)++;
			check_type(conv, temp, ap);
		}
		else
			fill_conv_struct(*conv, *temp, ap);
	}
	return (**conv);
}

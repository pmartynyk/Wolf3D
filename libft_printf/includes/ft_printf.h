/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:40:15 by pmartyny          #+#    #+#             */
/*   Updated: 2018/11/26 11:40:17 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

int		g_len;

typedef struct			s_conv_template {
	int					flag_zero;
	int					flag_minus;
	int					flag_plus;
	int					flag_space;
	int					flag_sharp;
	int					field_wigth;
	int					presicion;
	enum {
		no,
		h,
		hh,
		l,
		ll,
		L
	}					length;
	char				type;
}						t_conv_template;

int						ft_printf(char *param, ...);
void					ft_putunbr(unsigned long long int n);
void					ft_putuhhnbr(unsigned char n);
void					ft_putonbr(unsigned long long int n);
void					ft_putohhnbr(unsigned char n);
void					ft_putlnbr(long long int n);
void					ft_putdhhnbr(char n);
void					ft_putnstr(char *s, int len);
char					*ft_strnchr(char *src, int cnt);
unsigned long long int	ft_dec_to_oct(unsigned long long int num);
char					*ft_itoa_base(unsigned long long int n,
	int base, char type);
char					*n_pos(unsigned long long int n, int base, char type);
unsigned long long int	ft_atoi_oct(const char *src);
int						ft_atoi_base(char *src, int base);
unsigned long long int	result_oct(const char *s);
int						print_conversion(char *param, va_list ap);
int						fill_conv_struct(char **conv, t_conv_template temp,
	va_list ap);
int						check_str(char conv);
void					process_conversion(t_conv_template temp, va_list ap);
int						ft_intlen(int long long n);
int						ft_unsigned_intlen_oct(unsigned long long int n);
int						ft_unsigned_charlen_oct(unsigned char n);
void					*my_bzero(t_conv_template *temp);
int						ft_unsigned_intlen(unsigned long long int n);
int						ft_signed_charlen(signed char n);
int						ft_unsigned_charlen(unsigned char n);
char					*check_conv_flag(char ***conv, t_conv_template *temp);
char					*check_field_wigth(char ***conv, t_conv_template *temp);
char					*check_presicion(char ***conv, t_conv_template *temp);
char					*check_length(char ***conv, t_conv_template *temp);
char					*check_type(char ***conv, t_conv_template *temp,
	va_list ap);
void					process_d(t_conv_template temp, va_list ap);
void					process_u(t_conv_template temp, va_list ap);
void					process_o(t_conv_template temp, va_list ap);
void					process_x(t_conv_template temp, va_list ap);
void					process_d_no_length(t_conv_template temp, va_list ap);
void					process_d_l_length(t_conv_template temp, va_list ap);
void					process_d_ll_length(t_conv_template temp, va_list ap);
void					process_d_h_length(t_conv_template temp, va_list ap);
void					process_d_hh_length(t_conv_template temp, va_list ap);
void					process_d_plus_minus_flags(t_conv_template temp,
	long long int num);
void					process_d_plus(t_conv_template temp, long long int num);
void					process_d_minus(t_conv_template temp,
	long long int num);
void					process_d_plus_and_minus(t_conv_template temp,
	long long int num);
void					process_d_else(t_conv_template temp, long long int num);
void					print_else(t_conv_template *temp, int len_num,
	long long int num);
void					process_d_plus_minus_flags_hh(t_conv_template temp,
	char num);
void					process_d_plus_hh(t_conv_template temp, char num);
void					process_d_minus_hh(t_conv_template temp, char num);
void					process_d_plus_and_minus_hh(t_conv_template temp,
	char num);
void					print_else_hh(t_conv_template *temp, int len_num,
	char num);
void					process_d_else_hh(t_conv_template temp, char num);
void					print_space_prefix_hh(t_conv_template *temp, char num);
void					print_minus_prefix(t_conv_template *temp, int num);
char					*convert_f(long double num, t_conv_template temp);
void					push_res(char **res, long double *num);
void					print_zero_sign(int num);
void					process_o_no_length(t_conv_template temp, va_list ap);
void					process_o_l_length(t_conv_template temp, va_list ap);
void					process_o_ll_length(t_conv_template temp, va_list ap);
void					process_o_h_length(t_conv_template temp, va_list ap);
void					process_o_hh_length(t_conv_template temp, va_list ap);
void					process_o_minus_flags(t_conv_template temp,
	unsigned long long int num);
void					process_o_else(t_conv_template temp,
	unsigned long long int num);
void					process_o_else_add(t_conv_template temp,
	unsigned long long int num);
void					process_o_minus_flags_hh(t_conv_template temp,
	unsigned char num);
void					process_o_else_hh(t_conv_template temp,
	unsigned char num);
void					process_o_else_add_hh(t_conv_template temp,
	unsigned char num);
void					process_u_no_length(t_conv_template temp, va_list ap);
void					process_u_l_length(t_conv_template temp, va_list ap);
void					process_u_ll_length(t_conv_template temp, va_list ap);
void					process_u_h_length(t_conv_template temp, va_list ap);
void					process_u_hh_length(t_conv_template temp, va_list ap);
void					process_u_plus_minus_flags(t_conv_template temp,
	unsigned long long int num);
void					process_u_plus_flags(t_conv_template temp,
	unsigned long long int num);
void					process_u_else(t_conv_template temp,
	unsigned long long int num);
void					process_u_plus_minus_flags_hh(t_conv_template temp,
	unsigned char num);
void					process_u_plus_flags_hh(t_conv_template temp,
	unsigned char num);
void					process_u_else_hh(t_conv_template temp,
	unsigned char num);
void					process_x_no_length(t_conv_template temp, va_list ap);
void					process_x_l_length(t_conv_template temp, va_list ap);
void					process_x_ll_length(t_conv_template temp, va_list ap);
void					process_x_h_length(t_conv_template temp, va_list ap);
void					process_x_hh_length(t_conv_template temp, va_list ap);
void					process_x_minus_flags(t_conv_template temp, char *num);
void					process_x_else(t_conv_template temp, char *num);
void					print_x_sharp(t_conv_template *temp, char *num);
void					print_x_not_sharp(t_conv_template *temp, char *num);
void					print_x_prefix(t_conv_template *temp, char *num);
void					process_c(t_conv_template temp, va_list ap);
void					process_s(t_conv_template temp, va_list ap);
void					process_p(t_conv_template temp, va_list ap);
void					process_interest(t_conv_template temp, va_list ap);
void					process_f(t_conv_template temp, va_list ap);
void					process_f_no_length(t_conv_template temp, va_list ap);
void					process_f_l_length(t_conv_template temp, va_list ap);
void					process_c_zero(t_conv_template temp, char val);
void					process_c_minus(t_conv_template temp, char val);
void					process_c_else(t_conv_template temp, char val);
void					process_s_minus(t_conv_template temp, char *val);
void					process_s_else(t_conv_template temp, char *val);
void					process_p_minus(t_conv_template temp, char *num);
void					process_p_else(t_conv_template temp, char *num);
void					print_p_presicion(t_conv_template *temp, char *num);
void					process_interest_minus(t_conv_template temp, char val);
void					process_interest_else(t_conv_template temp, char val);
void					process_f_plus_minus_flags(t_conv_template temp,
	char *num);
void					process_f_plus(t_conv_template temp, char *num);
void					process_f_minus(t_conv_template temp, char *num);
void					process_f_plus_and_minus(t_conv_template temp,
	char *num);
void					process_f_else(t_conv_template temp, char *num);
void					print_else_f(t_conv_template *temp, int len_num,
	char *num);

#endif

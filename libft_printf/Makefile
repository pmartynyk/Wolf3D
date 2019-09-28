# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 09:38:43 by pmartyny          #+#    #+#              #
#    Updated: 2018/11/12 16:30:51 by pmartyny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ./includes/

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putnbr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_putchar_fd.c\
	ft_putendl.c\
	ft_putendl_fd.c\
	ft_itoa.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_printf.c\
	print_conversion.c\
	check_conv.c\
	additional_function.c\
	ft_putnstr.c\
	process_function.c\
	process_d_length.c\
	process_d_plus_minus.c\
	process_d_else.c\
	process_d_plus_minus_flags_hh.c\
	process_d_else_hh.c\
	process_additional.c\
	process_u_length.c\
	process_u.c\
	process_u_hh.c\
	process_o_length.c\
	process_o.c\
	process_o_hh.c\
	process_x_length.c\
	process_x.c\
	process_function_csp.c\
	process_c.c\
	process_s.c\
	process_p.c\
	process_interest.c\
	process_f_length.c\
	process_f_plus_minus.c\
	process_f_else.c\
	ft_putunbr.c\
	ft_putonbr.c\
	ft_strnchr.c\
	ft_dec_to_oct.c\
	ft_itoa_oct.c\
	ft_atoi_oct.c\
	ft_atoi_base.c\
	ft_putlnbr.c\
	additional_function_2.c\
	get_next_line.c\
	ft_strcut.c

OB = $(SOURCE:%.c=%.o)

all: $(NAME)

$(OB):%.o:%.c
	@$(CC) -c $(FLAGS) -I$(LIB) $< -o $@

$(NAME): $(OB)
	@ar rc $(NAME) $(OB)
	@ranlib $(NAME)

clean: 
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all


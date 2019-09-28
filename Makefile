
NAME	= wolf3d

GCC 	= gcc

FLAG	= -Wall -Wextra -Werror

OGL 	= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIB 	= wolf3d.h

MYLIB	= libft_printf/libftprintf.a

SRC		= main.c\
		read.c\
		additional.c
		

LIBS_DIR = ./includes/

SRC_DIR = ./src/

OBJ_DIR = ./objects/

SRCF = $(addprefix $(SRC_DIR), $(SRC))
LIBF = $(addprefix $(LIBS_DIR), $(LIB))
OBJF = $(addprefix $(OBJ_DIR), $(OBJ))

OBJ		= $(SRC:.c=.o)

all: mkdir $(NAME)
	
mkdir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJF) $(LIBF) mylib
	@$(GCC) $(OGL) $(FLAG) $(OBJF) $(MYLIB) -o  $(NAME) 
	@echo "\033[32mWolf3D Builded\033[39m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(GCC) $(FLAG) -c $< -o $@ -g

mylib:
	@make -C ./libft_printf/
	@echo "\033[32mMy lib Builded\033[39m"

clean:
	@rm -rf $(OBJ_DIR)
	@/bin/rm -f *.o
	@make -C libft_printf clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft_printf fclean

re: fclean all

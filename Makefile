# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malancar <malancar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 02:44:56 by malancar          #+#    #+#              #
#    Updated: 2023/06/21 19:25:34 by malancar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc

RM	= rm -f

NAME	= fractol

CFLAGS	= -Wextra -Werror -Wall -g -O3

MLX_PATH	= ./mlx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

INC			=	-I ./mlx/

MLXFLAG = -lXext -lX11 -lm

SRC		= check.c			\
		  color.c			\
		  fractol_utils.c	\
		  ft_atof.c			\
		  init.c			\
		  julia.c			\
		  key_event.c		\
		  main.c			\
		  mandelbrot.c		\
		  mouse_event.c		\
		  multibrot.c		\
		  newton.c			

OBJ =	$(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

HEADER = fractol.h

all:	 $(NAME)

$(NAME):	$(OBJ) $(HEADER)
		make -C ./mlx all
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX) $(INC) $(MLXFLAG)

%.o:	%.c
	@$(CC) $(CFLAGS) -MMD -c  $< -o $@

clean:
	$(RM) $(OBJ) $(DEPS)
	make -C ./mlx clean

fclean: clean
	@$(RM) $(NAME) $(DEPS)

re:	fclean all

-include : $(DEPS)

.PHONY: all clean fclean re mlx

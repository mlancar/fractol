# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malancar <malancar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 02:44:56 by malancar          #+#    #+#              #
#    Updated: 2023/04/27 19:03:05 by malancar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

RM	= rm -f

NAME	= fractol

CFLAGS	= -Wextra -Werror -Wall -g -O3

SRC		= ft_atof.c			\
		  check.c			\
		  color.c			\
		  fractol_utils.c	\
		  ft_atof.c			\
		  init.c			\
		  julia.c			\
		  key_event.c		\
		  mandelbrot.c		\
		  mouse_event.c		\
		  multibrot.c		\
		  newton.c			

OBJ =	$(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

HEADER = push_swap.h

all:	$(NAME)

$(NAME):	 $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) -MMD -c  $< -o $@

clean:
	@$(RM) $(OBJ) $(DEPS)

fclean: clean
	@$(RM) $(NAME) $(DEPS)

re:	fclean all

-include : $(DEPS)

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rweiss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 12:08:33 by rweiss            #+#    #+#              #
#    Updated: 2017/05/22 12:06:29 by rweiss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fractol.h

SRC =	main.c \
	 	disp_and_tools.c \
	 	environment.c \
		events.c \
		julia.c \
		mandelbrot.c \
		newton.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)


$(NAME):
	@make -C libft/
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft ./libmlx.a -framework OpenGL -framework AppKit
	@printf "\e[33;1mproject  \e[37;1m==>  \e[32;1mready\n"

.PHONY: clean fclean

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

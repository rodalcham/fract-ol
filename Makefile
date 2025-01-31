# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:21:39 by rchavez           #+#    #+#              #
#    Updated: 2025/01/31 13:45:48 by rchavez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/usr/local/include -Ofast

LFLAGS = -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

MLXLIB = ./MLX42

LIB = $(MLXLIB)/build/libmlx42.a

CFILES = main.c fractals.c rendering.c events.c image.c main_utils.c \
		ft_error.c parse_utils.c

MLX_NAME = ./MLX42/build/libmlx42.a

OFILES = $(CFILES:.c=.o)

all : $(MLX_NAME) $(NAME)

$(NAME) : $(MLX_NAME) $(OFILES)
	$(CC) $(CFLAGS) -o $@  $(LFLAGS) $(LIB) $(OFILES)


%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(MLX_NAME) : $(MLXLIB)
	@mkdir -p $(MLXLIB)/build
	@cd $(MLXLIB)/build && cmake .. && make -j4

$(MLXLIB) :
	@touch .gitmodules
	@git submodule add -f https://github.com/codam-coding-college/MLX42.git
	cd $(MLXLIB) && git checkout 4c275721d0de1a9c514c857c29e9dd235d874591

clean :
	@rm -f $(OFILES)

fclean : clean
	@rm -rf $(NAME) $(MLX_NAME)

re : fclean all

.PHONY : all, clean, fclean, re, mlx, getmlx
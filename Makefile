# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 19:45:56 by hlorrine          #+#    #+#              #
#    Updated: 2020/01/29 19:02:57 by hlorrine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/main.c src/read_maps.c src/save_maps.c src/paint.c src/colors.c src/conversion.c src/os_conversion.c src/press_keyboard.c src/bresenham_algorithm.c
LIB = libft/libft.a
NAME = fdf
OBJ = $(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft re
	@gcc -L libft -lft $(FILES) -I libft -I src/fdf.h -o $(NAME) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
%.o: %.c
	@gcc -I src/fdf.h $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
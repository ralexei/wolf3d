# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alrusu <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 17:29:30 by alrusu            #+#    #+#              #
#    Updated: 2017/06/27 18:19:08 by alrusu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC = blabla.c floor_ceil.c image_loader.c input.c main.c map_reader.c \
	  pixel_put.c tools.c wall_drawer.c
OFILES = $(SRC:%.c=%.o)

all: $(NAME)
	make -C wolf3d_mapEditor
	@mv wolf3d_mapEditor/wolf3d_map .

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -lmlx -framework OpenGL \
		-framework AppKit -lm -Ofast

%.o: %.c wolf.h keys.h
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OFILES) wolf.h.gch keys.h.gch
	make -C wolf3d_mapEditor clean

fclean: clean
	@rm -f $(NAME)
	rm wolf3d_map
	make -C wolf3d_mapEditor fclean

re: fclean all

.PHONY: all clean

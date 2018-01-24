# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abadraja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 15:18:20 by abadraja          #+#    #+#              #
#    Updated: 2017/05/17 13:50:14 by abadraja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d_map
SRCS = srcs/*.c 
LIBS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit -lm
CC = gcc
FLAGS = -Wall -Werror -Wextra -Ofast

all: $(NAME)

$(NAME):
		make -C libft
			$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)

clean:
		make -C libft clean

fclean:
		make -C libft fclean
			rm -rf $(NAME)
fast:
	$(CC) $(FLAGS) $(SRCS) $(LIBS) -o $(NAME)

re: fclean all

.PHONY: all clean

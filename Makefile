# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbarros <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:26:17 by fbarros           #+#    #+#              #
#    Updated: 2021/11/08 13:36:00 by fbarros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -lm

all: $(NAME)

clean: 
	rm $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 13:11:28 by jlinguet          #+#    #+#              #
#    Updated: 2024/02/10 16:11:22 by jlinguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c \
      parser.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror 

${NAME}: ${OBJ}
	make -C libft
	make -C ft_printf
	cc ${OBJ} -o pipex -Lft_printf -lftprintf -Llibft -lft

all: ${NAME}

clean:
	make $@ -C ft_printf
	make $@ -C libft
	rm -f ${OBJ}

fclean: clean
	make $@ -C libft
	make $@ -C ft_printf
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

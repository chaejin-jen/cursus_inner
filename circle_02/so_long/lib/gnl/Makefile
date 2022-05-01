# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:37:27 by chaejkim          #+#    #+#              #
#    Updated: 2022/05/02 01:31:48 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LFT = ../libft/libft.a

INC = -I. -I../libft
LIB = -L../libft -lft

SRC = src/get_next_line.c

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

all: obj $(NAME)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	ar -cr $@ $^ $(LFT)

obj:
	@mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRC)
	@norminette get_next_line.h

.PHONY: all clean fclean re

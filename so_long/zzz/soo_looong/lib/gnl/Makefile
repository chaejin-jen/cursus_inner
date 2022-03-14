# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:37:27 by chaejkim          #+#    #+#              #
#    Updated: 2022/03/09 16:13:19 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#LFT = ../libft/libft.a

INC = -I.
#INC = -I../libft
#LIB = -L../libft -lft

SRC = src/get_next_line.c src/get_next_line_utils.c

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

all: obj $(NAME)

obj/%.o : src/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	ar -cr $@ $^

obj:
	@mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
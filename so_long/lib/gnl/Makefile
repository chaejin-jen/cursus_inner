# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:37:27 by chaejkim          #+#    #+#              #
#    Updated: 2022/03/04 22:37:38 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS)
	ar -cr $@ $^

clean:
	rm -f $(OBJECTS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
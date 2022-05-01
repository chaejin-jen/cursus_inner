# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:37:27 by chaejkim          #+#    #+#              #
#    Updated: 2022/01/26 18:08:22 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

#ifdef BONUS_FLAG
#	OBJ_SWITCH = $(OBJECTS) $(BOBJS)
#else
#	OBJ_SWITCH = $(OBJECTS)
#endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

#$(NAME): $(OBJ_SWITCH)
#	ar -cr $@ $^

$(NAME): $(OBJECTS)
	ar -cr $@ $^

clean:
	rm -f $(OBJECTS) $(BOBJS)

#bonus:
#	$(MAKE) BONUS_FLAG=1 $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re #bonus
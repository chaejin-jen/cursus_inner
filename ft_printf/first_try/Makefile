# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:05:28 by chaejkim          #+#    #+#              #
#    Updated: 2022/02/02 02:22:42 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SOURCES = ft_printf.c ft_prntchar.c ft_prntnbr.c ft_prntptr.c

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

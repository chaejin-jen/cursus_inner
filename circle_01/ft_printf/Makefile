# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:05:28 by chaejkim          #+#    #+#              #
#    Updated: 2022/02/22 17:55:14 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -I./include/

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = ft_printf ft_prntchar ft_prntnbr ft_prntptr ft_printf_utils

SOURCES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar -cr $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

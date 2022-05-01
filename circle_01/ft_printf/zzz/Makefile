# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:05:28 by chaejkim          #+#    #+#              #
#    Updated: 2022/02/06 20:50:15 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

INC_DIR = ./include/
FT_DIR = ./libft/
FT_INCLUDE_DIR = $(FT_DIR)
FT_ARCHIVE = $(FT_DIR)libft.a

SRC_DIR = ./src/mandatory/
BSRC_DIR = ./src/bonus/
OBJ_DIR = ./obj/

SRC_FILES = ft_printf ft_prntchar ft_prntnbr ft_prntptr \
			ft_printf_utils

BSRC_FILES = ft_printf_bonus ft_prntchar_bonus ft_prntnbr_bonus \
		     ft_prntptr_bonus ft_print_info_bonus ft_printf_utils_bonus

SOURCES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
BSRC = $(addprefix $(BSRC_DIR), $(addsuffix .c, $(BSRC_FILES)))

OBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BOBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BSRC_FILES)))

ifdef BONUS_FLAG
	OBJ_SWITCH = $(OBJECTS) $(BOBJS)
else
	OBJ_SWITCH = $(OBJECTS)
endif

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -I $(FT_INCLUDE_DIR) -o $@ 

$(OBJ_DIR)%.o : $(BSRC_DIR)%.c
	$(CC) $(CFLAGS) $< -I $(INC_DIR) -I $(FT_INCLUDE_DIR) -o $@

$(NAME): $(OBJ_SWITCH)
	ar -cr $@ $^

$(NAME): $(OBJECTS)
	$(MAKE)	-C $(FT_DIR)
	ar -cr $@ $^

clean:
	$(MAKE)	-C $(FT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -f $(OBJECTS) $(BOBJS)

bonus:
	$(MAKE) BONUS_FLAG=1 $(NAME)

fclean: clean
	$(MAKE) -C $(FT_DIR) fclean
	rm -f $(NAME) $(FT_ARCHIVE)

re: fclean all

.PHONY: all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:05:28 by chaejkim          #+#    #+#              #
#    Updated: 2022/02/22 17:38:52 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -I./include/ -I./lib/

LIB_DIR = ./lib/

SRC_DIR = ./src/mandatory/
BSRC_DIR = ./src/bonus/
OBJ_DIR = ./obj/

SRC_FILES = ft_printf ft_prntchar ft_prntnbr ft_prntptr ft_printf_utils

BSRC_FILES = ft_printf_bonus ft_prntchar_bonus ft_prntnbr_bonus ft_prntptr_bonus ft_printf_utils_bonus \
			 ft_p_info_bonus ft_p_info_apply_bonus

SOURCES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
BSRC = $(addprefix $(BSRC_DIR), $(addsuffix .c, $(BSRC_FILES)))

OBJECTS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BOBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BSRC_FILES)))

#$(CC) $(CFLAGS) $(CPPFLAGS) -L$(LIB_DIR) -lft $@ -o $(NAME)

ifdef BONUS_FLAG
OBJ_SWITCH = $(BOBJS)
$(OBJ_DIR)%.o : $(BSRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	libtool -static -o $(NAME) $(LIB_DIR)libft.a $@
else
OBJ_SWITCH = $(OBJECTS)
$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@
endif

all: $(NAME)

#$(NAME) : $(OBJ_SWITCH)
#	if [ -e $(LIB_DIR)libft.a ]; then \
#		echo bonus; \
#	else \
#		ar -cr $@ $^; \
#	fi

$(NAME) : $(OBJ_SWITCH)
	if [ -e $(LIB_DIR)libft.a ]; then \
		ranlib $@; \
	else \
		ar -cr $@ $^; \
	fi
	

clean:
	if [ -e $(LIB_DIR)libft.a ]; then \
		$(MAKE) -C $(LIB_DIR) clean; \
	fi
	rm -rf $(OBJ_DIR)

bonus:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) BONUS_FLAG=1 $(NAME)

fclean: clean
	if [ -e $(LIB_DIR)libft.a ]; then \
		rm -f $(LIB_DIR)libft.a; \
	fi
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

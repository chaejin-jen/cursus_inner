# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 13:41:40 by chaejkim          #+#    #+#              #
#    Updated: 2022/07/14 20:05:23 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
SAN_FLAG = -g3 -fsanitize=address

INC = -Iinclude

SRC = src/main.c \
	  src/print.c \
	  src/run_simulation.c \
	  src/routine.c \
	  src/routine_util.c \
	  src/monitor.c \
	  src/simulation_info.c \
	  src/table_info.c \
	  src/time_info.c

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

obj/%.o : src/%.c
	@$(CC) $(CFLAGS) $(SAN_FLAG) $(INC) -o $@ -c $<

all: obj $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(SAN_FLAG) $(INC) -o $@ $^

clean:
	rm -rf obj

fclean: clean
	@rm -rf $(NAME)

obj:
	@mkdir -p obj

re: fclean all

.PHONY: all clean fclean re

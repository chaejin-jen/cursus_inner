# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 13:41:40 by chaejkim          #+#    #+#              #
#    Updated: 2022/08/20 17:47:43 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
RACE_FLAG = -g3 -fsanitize=address
RACE_FLAG = -g -fsanitize=thread

INC = -Iinclude

SRC = src/main.c \
	  src/print.c \
	  src/run_simulation.c \
	  src/routine.c \
	  src/routine_act.c \
	  src/routine_util.c \
	  src/monitor.c \
	  src/simulation_info.c \
	  src/table_info.c \
	  src/time.c

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

obj/%.o : src/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: obj $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $@ $^

clean:
	rm -rf obj

fclean: clean
	@rm -rf $(NAME)

obj:
	@mkdir -p obj

re: fclean all

.PHONY: all clean fclean re

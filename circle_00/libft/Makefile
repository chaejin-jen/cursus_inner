# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 19:28:38 by chaejkim          #+#    #+#              #
#    Updated: 2022/01/08 21:53:18 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

NAME = libft.a

SOURCES = ft_toupper.c ft_tolower.c ft_isascii.c ft_isprint.c ft_isdigit.c \
		  ft_isalpha.c ft_isalnum.c ft_strncmp.c ft_strlen.c ft_strlcpy.c \
		  ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strnstr.c \
		  ft_memset.c ft_bzero.c ft_memchr.c ft_memmove.c ft_memcmp.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_striteri.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(SOURCES:.c=.o)
BOBJS = $(BSRCS:.c=.o)

ifdef BONUS_FLAG
	OBJ_SWITCH = $(OBJECTS) $(BOBJS)
else
	OBJ_SWITCH = $(OBJECTS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ_SWITCH)
	ar -cr $@ $^

clean:
	rm -f $(OBJECTS) $(BOBJS)

bonus:
	$(MAKE) BONUS_FLAG=1 $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean bonus fclean re
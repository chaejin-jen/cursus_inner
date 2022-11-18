NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = test.cpp Account.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^

all : $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
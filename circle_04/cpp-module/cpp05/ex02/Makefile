NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp PresidentialPardonForm.cpp
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

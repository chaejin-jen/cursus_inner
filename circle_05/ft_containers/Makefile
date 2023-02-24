NAME = containers
TESTER = benchmark
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SANFLAG = # -g3 -fsanitize=address

INC = -I./

SRC = main.cpp
TEST_SRC = test.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

%.o : %.cpp
	@$(CXX) $(CXXFLAG) $(INC) -c $< -o $@

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

benchmark:
	@$(CXX) $(CXXFLAG) $(SANFLAG) $(TEST_SRC) -o $(TESTER) $(INC)
	@./$(TESTER)
	rm $(TESTER)
.PHONY: all clean fclean re benchmark

NAME := test
CXX := c++
CXXFLAGS := # -Wall -Wextra -Werror -std=c++98
SANFLAGS := -g3 -fsanitize=address

CONTAINERSDIR := ..
INC := -Iinc -I$(CONTAINERSDIR)

SRC := $(addprefix src/, \
	  main.cpp \
	  test_vector.cpp \
	  )
OBJ := $(patsubst src%, obj%, $(SRC:.cpp=.o))

obj/%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

all : obj $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

obj:
	@mkdir -p obj

debug:
	$(CXX) $(CXXFLAG) $(SANITIZER) $(INC) $(TEST_SRCS) -o $@

.PHONY: all clean fclean re debug

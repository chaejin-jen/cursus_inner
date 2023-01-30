NAME := test
CXX := c++
CXXFLAGS := -std=c++98 -D STD_VERSION # -Wall -Wextra -Werror -std=c++98
DBGFLAGS := -g #-fsanitize=address

CONTAINERSDIR := ..
INC := -Iinc -I$(CONTAINERSDIR)

SRC := $(addprefix src/, \
	  main.cpp \
	  test_vector.cpp \
	  test_type_traits.cpp \
	  )
OBJ := $(patsubst src%, obj%, $(SRC:.cpp=.o))

obj/%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) $(INC) -o $@ -c $<

all : obj $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(DBGFLAGS) $(INC) -o $@ $^

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

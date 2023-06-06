NAME = Bureaucrat
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Bureaucrat.hpp
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf Bureaucrat

re: fclean all

.PHONY: clean fclean re all

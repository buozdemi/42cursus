NAME = identify
SRCS = main.cpp Base.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Base.hpp A.hpp B.hpp C.hpp
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf identify

re: fclean all

.PHONY: all clean fclean re

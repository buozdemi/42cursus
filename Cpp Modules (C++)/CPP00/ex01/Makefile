NAME = phonebook
SRCS = main.cpp add_data.cpp Contact.cpp Phonebook.cpp
OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Phonebook.hpp Contact.hpp
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf phonebook

re: fclean all

.PHONY: clean fclean re all

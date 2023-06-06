NAME = philo
SRCS = controls.c \
		ft_atoi.c \
		init.c \
		life.c \
		main.c \
		time.c \
		exitlife.c \
		lifeutils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	gcc $(CFLAGS) $< -c -o $@

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f philo

re: fclean all

.PHONY: clean fclean re all
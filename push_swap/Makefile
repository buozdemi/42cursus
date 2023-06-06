NAME	= push_swap
SRCS	= $(wildcard ./*.c)
OBJS	= $(SRCS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror
PF		= ftprintf/libftprintf.a
LBFT	= libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(PF) $(LBFT)
	gcc $(CFLAGS) $(LBFT) $(PF) $(OBJS) -o $(NAME)

$(LBFT):
	make -C ./libft

$(PF):
	make -C ./ftprintf

clean:
	make -C ./ftprintf fclean
	make -C ./libft fclean
	rm -rf $(OBJS)

fclean: clean
	rm -f push_swap

re: fclean all

.PHONY: clean fclean re all
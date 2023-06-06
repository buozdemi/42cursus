NAME		= server client
SRCS		= $(wildcard ./*.c)
OBJS		= $(SRCS:.c=.o)
LBFT		= libft/libft.a
PF			= ftprintf/libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -L./ftprintf -lftprintf -L./libft -lft

all: server client

server: server.o $(LBFT) $(PF)
	gcc $(CFLAGS) $(LFLAGS) server.o -o server

client: client.o $(LBFT) $(PF)
	gcc $(CFLAGS) $(LFLAGS) client.o -o client

$(LBFT):
	make -C ./libft

$(PF):
	make -C ./ftprintf

clean:
	make -C ./ftprintf clean
	make -C ./libft clean
	rm -rf server.o
	rm -rf client.o

fclean:
	make -C ./ftprintf fclean
	make -C ./libft fclean
	rm -rf server.o
	rm -rf client.o
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
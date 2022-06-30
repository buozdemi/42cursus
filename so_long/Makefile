NAME		= so_long
SRCS		= $(wildcard support/*.c) $(wildcard ./*.c)
OBJS		= $(SRCS:.c=.o)
LBFT		= libft/libft.a
PF			= ftprintf/libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit -L./mlx -lmlx -L./ftprintf -lftprintf -L./libft -lft

all: $(NAME)

$(NAME): $(OBJS) $(LBFT) $(PF)
	make -C ./mlx 2> /dev/null
	gcc $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

$(LBFT):
	make -C ./libft

$(PF):
	make -C ./ftprintf

clean:
	make -C ./mlx clean
	make -C ./ftprintf clean
	make -C ./libft clean
	rm -rf $(OBJS) 

fclean:
	make -C ./ftprintf fclean
	make -C ./libft fclean
	make -C ./mlx clean
	rm -rf $(OBJS) 
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
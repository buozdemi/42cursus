NAME	= cub3D
SRC 	= main.c \
		$(wildcard GNL/*.c) \
		$(wildcard utils/*.c) \
		$(wildcard controller/*.c) \
		$(wildcard game_map_handle/*.c) \
		$(wildcard mlx_image_setup/*.c) \
		$(wildcard start_game/*.c) \
		$(wildcard cleaner/*.c)
OBJ 	= $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -framework OpenGL -framework AppKit -L./mlx -lmlx
LBFT	= libft/libft.a
GREEN	= "\033[1;032m"
RED		= "\033[1;31m"

all : $(NAME)
	@echo $(GREEN) make OK

$(NAME): $(OBJ) $(LBFT)
	@make -C ./mlx 2> /dev/null
	@gcc $(CFLAGS) $(LFLAGS) $(LBFT) $(OBJ) -o $(NAME)

$(LBFT):
	make -C ./libft

clean :
	@make -C ./mlx clean
	@make -C ./libft fclean
	@rm -rf $(OBJ)
	@echo $(GREEN) clean OK

fclean : clean
	@make -C ./mlx clean
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@echo $(GREEN) fclean OK

re : fclean all

.PHONY: clean fclean re all
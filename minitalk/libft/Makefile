NAME = libft.a

OBJS = ft_atoi.o \
	   ft_itoa.o \
	   ft_strlen.o \
	   ft_strdup.o \
	   ft_calloc.o \
	   ft_strlcpy.o \
	   ft_memset.o

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

.c.o:
	gcc -Wall -Wextra -Werror -c $^

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
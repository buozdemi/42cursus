NAME = libft.a

OBJS = ft_calloc.o \
	   ft_memset.o \
	   ft_split.o \
	   ft_strdup.o \
	   ft_strjoin.o \
	   ft_strlcpy.o \
	   ft_strlen.o \
	   ft_substr.o

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
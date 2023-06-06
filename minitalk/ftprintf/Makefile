NAME = libftprintf.a

OBJS = ft_put_pointer.o \
	   ft_putchar_newfd.o \
	   ft_putnbr_newfd.o \
	   ft_putstr_newfd.o \
	   ft_put_base.o \
	   ft_printf.o

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
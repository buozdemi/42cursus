O_DOSYALARI = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
ft_memmove.o ft_memset.o ft_split.o ft_strchr.o ft_strdup.o ft_strjoin.o \
ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o \
ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o ft_putendl_fd.o ft_putnbr_fd.o \
ft_putchar_fd.o ft_putstr_fd.o ft_strmapi.o ft_itoa.o ft_striteri.o

O_DOSYALARI_BONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstclear.o \
ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o

NAME = libft.a

all: $(NAME)

$(NAME): $(O_DOSYALARI)
	ar -rcs $(NAME) $^

.c.o:
	gcc -Wall -Wextra -Werror -c $^
 
bonus: $(O_DOSYALARI_BONUS) $(O_DOSYALARI)
	ar -rcs $(NAME) $^

clean:
	rm -f $(O_DOSYALARI) $(O_DOSYALARI_BONUS)

fclean:
	rm -f $(O_DOSYALARI) $(O_DOSYALARI_BONUS) $(NAME)

re: fclean all

.PHONY: clean fclean re all
NAME = minishell
SRCS =	token_machine/string_handle.c \
		token_machine/token_classify.c \
		token_machine/token_fill_and_link.c \
		free_machine/free_array.c \
		free_machine/free_process.c \
		free_machine/free_tokens.c \
		get_data/env_var_finder.c \
		get_data/envcopy.c \
		get_data/expcopy.c \
		get_data/is_valid_cmd_path.c \
		get_data/split_paths.c \
		lexer_machine/lexer.c \
		lexer_machine/process_fill_and_link.c \
		cmd_machine/close_fd.c \
		cmd_machine/pipe_handle.c \
		cmd_machine/run_cmd.c \
		cmd_machine/start_cmd.c \
		redirs/heredoc_handle.c \
		redirs/input_output_handle.c \
		redirs/redir_check.c \
		redirs/redirs_classify.c \
		builtin/builtin_check.c \
		builtin/ft_cd.c \
		builtin/ft_echo.c \
		builtin/ft_env.c \
		builtin/ft_exit.c \
		builtin/ft_export.c \
		builtin/ft_pwd.c \
		builtin/ft_unset.c \
		builtin/get_builtin.c \
		builtin/run_builtin.c \
		fix_up_the_arguments/dollar_handle.c \
		fix_up_the_arguments/fix_up_the_arguments.c \
		fix_up_the_arguments/quotes_handle.c \
		utils/add_env.c \
		utils/add_export.c \
		utils/already_exist.c \
		utils/env_len.c \
		utils/equal_len.c \
		utils/ft_strcmp.c \
		utils/is_parent.c \
		utils/is_valid_export.c \
		utils/make_export_fit.c \
		main.c \
		readline_cycle.c \
		error.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LBFT = libft/libft.a

all: $(NAME)

.c.o:
	@gcc $(CFLAGS) $< -c -o $@

$(NAME): $(OBJS) $(LBFT)
	@gcc -lreadline $(LBFT) $(OBJS) -o $(NAME)
	@echo OK.

$(LBFT):
	@make -C ./libft

clean:
	@make -C ./libft fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -f minishell

re: fclean all

.PHONY: clean fclean re all
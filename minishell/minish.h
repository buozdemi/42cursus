/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:00:23 by aoner             #+#    #+#             */
/*   Updated: 2022/11/17 16:23:07 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft/libft.h"

enum e_ttype
{
	PIPE = 1,
	STRING,
	APPEND_BELOW,
	OVER_WRITE,
	HERE_DOC,
	RED_INPUT
};

enum e_builtin_types
{
	CD = 1,
	ENV,
	PWD,
	ECHO,
	EXIT,
	UNSET,
	EXPORT
};

typedef struct s_token
{
	char			*str;
	enum e_ttype	type;
	struct s_token	*next;
	struct s_token	*back;
}	t_token;

typedef struct s_process
{
	int					fd[2];
	pid_t				pid;
	char				**execute;
	char				**redirs;
	int					heredoc_fd[2];
	struct s_process	*back;
	struct s_process	*next;
}	t_process;

typedef struct s_minish
{
	char		**split_path;
	int			parent_pid;
	char		**envcopy;
	char		**expcopy;
	int			ignore;
	t_token		*token;
	t_process	*process;
	int			parscount;
}	t_minish;

extern t_minish	g_ms;

int			main(int argc, char **argv, char **env);
void		envcopy(char **env);
void		split_paths(void);
void		token_classify(char *str);
size_t		line_len(char **s);
void		free_array(char **array);
char		*find_and_pull(char *str);
void		readline_cycle(void);
int			redir_check(char *str);
int			builtin_check(char *command);
int			link_the_tokens(t_token	**token, t_token *last_token, int plus);
t_token		*fill_the_token(char *str, enum e_ttype token_type);
void		string_handle(char **str);
int			lexer(void);
t_process	*fill_the_process(void);
void		link_the_process(t_process **process, t_process *last_process);
int			fix_up_the_arguments(t_token **token, t_process *process);
char		*is_there_dollar(char *str);
void		push_new_str(char **new_str, char *str);
char		*quotes_handle(char *str);
char		**push_array(char **arg_arr, char *str);
void		free_token(void);
int			valid_char(char c);
void		start_cmd(void);
void		fill_the_heredocs(void);
int			ft_strcmp(const char *s1, const char *s2);
void		close_all_fd(void);
int			is_there_heredoc(t_process *process);
void		redir_input_type(t_process *process);
void		redir_output_type(t_process *process);
void		no_file_direct_err(char *str);
int			is_parent(void);
void		run_builtin(char **execute);
void		ft_cd(char **input);
void		ft_env(void);
void		ft_pwd(void);
void		ft_echo(char **input);
void		ft_exit(char **input);
void		ft_unset(char **input);
void		ft_export(char **execute);
void		directory_err(char *str);
void		token_err(int type);
void		command_err(char *str);
char		*is_valid_cmd_path(char *cmd);
void		run_cmd(t_process *process);
void		output_type_handle(char *file, int mode);
void		input_type_handle(char *file);
void		heredoc(int *hdoc_fd, char *endline);
void		free_process(void);
void		ctrl_d(char *input);
void		ctrl_c(int sig);
void		init_signals(char *str);
void		get_builtin(t_process *process);
void		pipe_handle(t_process *process);
void		pipe_for_heredoc(t_process *process);
void		pipe_for_all_others(t_process *process);
void		pipe_for_all_others(t_process *process);
void		only_export(void);
void		expcopy(char **env);
char		*untilequal_i(char *env);
char		*add_marked(char *esittirvesonrasi);
int			equal_len(char *env);
char		*make_export_fit(char *env_line);
int			is_valid_export(char *str);
int			env_len(void);
int			already_exists_in_exp(char *str);
int			already_exists_in_env(char *str);
void		add_env(char *str);
void		add_export(char *str, int flag);
int			export_len(void);
int			is_valid_unset(char *str);
void		wrong_char_export(char *str);

#endif
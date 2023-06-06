/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:03:31 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:36:39 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	command_err(char *str)
{
	errno = 127;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", 20);
	if (!is_parent())
		exit(errno);
}

void	token_err(int type)
{
	char	*red;

	if (type == HERE_DOC)
		red = "<<";
	else if (type == RED_INPUT)
		red = "<";
	else if (type == OVER_WRITE)
		red = ">";
	else if (type == APPEND_BELOW)
		red = ">>";
	else if (type == PIPE)
		red = "|";
	else
		red = "newline";
	errno = 258;
	write(2, "minishell: syntax error near unexpected token '", 47);
	write(2, red, ft_strlen(red));
	write(2, "'\n", 2);
}

void	directory_err(char *str)
{
	errno = 126;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	if (!is_parent())
		exit(errno);
}

void	no_file_direct_err(char *str)
{
	if (ft_strchr(str, '/'))
		errno = 127;
	else
		errno = 1;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
	if (!is_parent())
		exit(errno);
}

void	wrong_char_export(char *str)
{
	errno = 1;
	write(2, "minishell: export: ", 19);
	write(2, str, ft_strlen(str));
	write(2, ": not a valid identifier\n", 25);
	if (!is_parent())
		exit(errno);
}

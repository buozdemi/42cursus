/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:02:43 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:43:49 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	output_type_handle(char *file, int mode)
{
	int		fd;

	fd = 0;
	if (mode == 1)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	else if (mode == 0)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
	{
		perror("minish ");
		if (is_parent())
			return ;
		else
			exit(errno);
	}
	dup2(fd, 1);
	close(fd);
}

void	input_type_handle(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (no_file_direct_err(file));
	dup2(fd, 0);
	close(fd);
}

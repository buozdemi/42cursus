/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:53:59 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/24 15:00:42 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	int		reader_bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader_bytes = 1;
	while (reader_bytes != 0 && !has_return(save))
	{
		reader_bytes = read(fd, buffer, BUFFER_SIZE);
		if (reader_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (0);
	save[fd] = ft_read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (line);
}
/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		file_descriptor;
	int		file_descriptor2;

	file_descriptor = open("text.txt", O_RDONLY);
	file_descriptor2 = open("text2.txt", O_RDONLY);
	printf("%d\n", file_descriptor);
	line = get_next_line(file_descriptor);
	free(line);
	printf("%d\n", file_descriptor2);
	line = get_next_line(file_descriptor2);
	free(line);
	printf("%d\n", file_descriptor);
	line = get_next_line(file_descriptor);
	free(line);
	printf("%d\n", file_descriptor2);
	line = get_next_line(file_descriptor2);
	free(line);
	return (0);
} */

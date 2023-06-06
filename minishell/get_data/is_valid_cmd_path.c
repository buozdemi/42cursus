/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:51:25 by aoner             #+#    #+#             */
/*   Updated: 2022/11/12 13:51:25 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	check_dir(char *cmd)
{
	DIR	*dir;

	if (!cmd)
		exit(EXIT_SUCCESS);
	dir = opendir(cmd);
	if (dir && readdir(dir))
	{
		closedir(dir);
		directory_err(cmd);
	}
}

char	*strjoin_ret_free(char *mim, char *path)
{
	free(mim);
	return (path);
}

char	*is_valid_cmd_path(char *cmd)
{
	char	*path;
	char	**paths;
	char	*new_cmd;

	check_dir(cmd);
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	paths = g_ms.split_path;
	if (!paths)
		command_err(cmd);
	new_cmd = ft_strjoin("/", cmd);
	while (*paths)
	{
		path = ft_strjoin(*paths, new_cmd);
		if (!access(path, F_OK))
			return (strjoin_ret_free(new_cmd, path));
		free(path);
		paths++;
	}
	if (ft_strchr(cmd, '/'))
		no_file_direct_err(cmd);
	free(new_cmd);
	return (NULL);
}

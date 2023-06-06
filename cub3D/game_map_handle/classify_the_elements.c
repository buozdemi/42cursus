/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_the_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:19:28 by aoner             #+#    #+#             */
/*   Updated: 2023/01/03 13:11:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	clear_pixel(char *s)
{
	char	*ss;
	int		c;
	int		i;

	i = 0;
	ss = ft_strtrim(s, " \n\t\v\f\r");
	while (ss && ss[i])
	{
		if (!ft_isdigit(ss[i]))
		{
			free(ss);
			return (-1);
		}
		i++;
	}
	c = ft_atoi(ss);
	free(ss);
	if (c > 255 || c < 0)
		return (-1);
	return (c);
}

static int	pixel_handle(t_pixel *p, char *cmp, char *s)
{
	int		i;
	char	**sp;
	int		f;

	f = -1;
	i = ft_strlen(cmp);
	sp = ft_split(&s[i], ',');
	i = 0;
	while (sp[i])
		i++;
	if (i == 3)
	{
		p->r = clear_pixel(sp[0]);
		p->g = clear_pixel(sp[1]);
		p->b = clear_pixel(sp[2]);
		if (p->r >= 0 && p->g >= 0 && p->b >= 0)
			f = 1;
	}
	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (f);
}

static char	*texture_handle(char *type, char *s)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	if (ft_strncmp(type, s, ft_strlen(type)) != 0)
		return (NULL);
	i = ft_strlen(type);
	while (s[i] && is_space(s[i]))
		i++;
	tmp = ft_substr(s, i, ft_strlen(&s[i]));
	return (tmp);
}

int	classify_the_elements_inner(t_data *data, int i)
{
	char	*line;

	line = ft_strtrim(data->collect_lines[i], " \n\t\v\f\r");
	if (!data->no && 0 == ft_strncmp("NO ", line, ft_strlen("NO ")))
		data->no = texture_handle("NO ", line);
	else if (!data->so && 0 == ft_strncmp("SO ", line, ft_strlen("SO ")))
		data->so = texture_handle("SO ", line);
	else if (!data->ea && 0 == ft_strncmp("EA ", line, ft_strlen("EA ")))
		data->ea = texture_handle("EA ", line);
	else if (!data->we && 0 == ft_strncmp("WE ", line, ft_strlen("WE ")))
		data->we = texture_handle("WE ", line);
	else if (!data->f.f && 0 == ft_strncmp("F ", line, ft_strlen("F ")))
		data->f.f = pixel_handle(&data->f, "F ", line);
	else if (!data->c.f && 0 == ft_strncmp("C ", line, ft_strlen("C ")))
		data->c.f = pixel_handle(&data->c, "C ", line);
	else if (line[0] != '\0')
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int	classify_the_elements(t_data *data)
{
	int	i;

	i = 0;
	while (data->collect_lines[i] && (!data->no || !data->so \
	|| !data->ea || !data->we || !data->f.f || !data->c.f))
	{
		if (classify_the_elements_inner(data, i) < 0)
			return (-1);
		i++;
	}
	return (i);
}

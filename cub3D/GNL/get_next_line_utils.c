/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:32:36 by aoner             #+#    #+#             */
/*   Updated: 2022/11/22 22:36:30 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlengnl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoingnl(char *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	m;

	if (!s2)
		return (NULL);
	i = 0;
	m = 0;
	p = (char *)malloc(((ft_strlengnl(s2) + \
	ft_strlengnl(s1)) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{	
		p[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[m])
		p[i++] = s2[m++];
	p[i] = '\0';
	return (p);
}

int	has_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

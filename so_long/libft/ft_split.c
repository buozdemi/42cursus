/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:55:12 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/07 15:55:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static size_t	wordcount(char *p, char m)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (p[i] != '\0')
	{
		while (p[i] == m)
			i++;
		if (p[i] == '\0')
			break ;
		while (p[i] != m && p[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static size_t	charcount(char *p, char m)
{
	size_t	i;

	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == m)
			return (i);
		i++;
	}
	return (i);
}

static void	free_list(char **f, size_t n, size_t m)
{
	while (n < m)
		free(f[n++]);
	free(f);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	size_t	i;
	size_t	m;

	if (!s)
		return (NULL);
	m = 0;
	i = 0;
	p = (char **)malloc(sizeof(char *) * (wordcount((char *)s, c) + 1));
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		p[m] = ft_substr(s, i, charcount((char *)&s[i], c));
		if (p[m] == NULL)
			free_list(p, 0, m);
		m++;
		i += charcount((char *)&s[i], c);
	}
	p[m] = NULL;
	return (p);
}

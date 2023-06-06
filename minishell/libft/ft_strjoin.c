/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:42:47 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/16 17:42:47 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	m;

	if (!s1 || !s2)
	{
		write(1, "Strjoin is returning NULL\n", 26);
		return (NULL);
	}
	i = 0;
	m = 0;
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[m] != '\0')
		p[i++] = s2[m++];
	p[i] = '\0';
	return (p);
}

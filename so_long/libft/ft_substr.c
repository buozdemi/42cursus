/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:37:59 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/07 15:53:24 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

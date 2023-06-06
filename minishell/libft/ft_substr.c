/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:32:11 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 15:27:07 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

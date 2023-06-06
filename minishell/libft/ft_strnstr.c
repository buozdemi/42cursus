/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:25:47 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 15:26:55 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		n = 0;
		while (needle[n] == haystack[i + n] && needle[n] != '\0' && i + n < len)
			n++;
		if (needle[n] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

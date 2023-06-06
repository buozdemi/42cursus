/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:33:42 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 15:26:40 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = ft_strlen(dst);
	if (dstsize <= m)
		return (dstsize + ft_strlen(src));
	while (src[i] != '\0' && m < dstsize - 1)
	{
		dst[m] = src[i];
		m++;
		i++;
	}
	dst[m] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}

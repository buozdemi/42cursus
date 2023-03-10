/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:33:42 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/26 17:12:02 by buozdemi         ###   ########.fr       */
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
/* 
int	main(void)
{
	const char	kaynak[20] = "dunya";
	char	hedef[20] = "merh";

	printf("%zu\n", ft_strlcat(hedef, kaynak, 12));
	printf("%zu\n", strlcat(hedef, kaynak, 12));
	printf("%zu\n", ft_strlcat(hedef, kaynak, 13));
	printf("%zu\n", strlcat(hedef, kaynak, 13));
} */
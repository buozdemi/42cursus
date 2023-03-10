/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:25:47 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/24 18:03:12 by buozdemi         ###   ########.fr       */
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
/* 
int	main()
{
	char	samanlik[] = "cokboyutlu";
	char	igne[] = "boy";

	printf("%s\n", ft_strnstr(samanlik, igne, 15));
	printf("%s\n", ft_strnstr(samanlik, igne, 5));
	printf("%s\n", ft_strnstr(samanlik, igne, 6));
	printf("%s\n", ft_strnstr(samanlik, igne, 7));
} */
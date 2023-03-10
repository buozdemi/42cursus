/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:24:51 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:31:56 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{	
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	return (dst);
}
/* 
int	main(void)
{
	char	kaynak[] = "PusatCakir";
	char	hedef[] = "PolatAlemdar";
	char	*p;
	char	*c;

	p = ft_memcpy(hedef, kaynak, 5);
	c = memcpy(hedef, kaynak, 5);
	printf("%s\n", p);
	printf("%s\n", c);
	return (0);
}
 */
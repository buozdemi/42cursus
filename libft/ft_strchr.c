/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:38:45 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/01 16:38:45 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}
/* 
int	main(void)
{
	const char	dizi[] = "Hayaletveyasa";
	char	*p;

	p = ft_strchr(dizi, 'l');
	printf("%s\n", p);
	return (0);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:39:51 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/27 19:43:33 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* 
int	main(void)
{
	char	dizi[] = "merkeziyetsiz";

	printf("%lu\n", ft_strlen(dizi));
	printf("%lu", strlen(dizi));
	return (0);
}
 */
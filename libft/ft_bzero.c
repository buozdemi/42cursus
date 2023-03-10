/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:17:13 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 19:21:04 by buozdemi         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}	
}
/* int	main(void)
{
	char	dizi[] = "Komutanlogar";

	printf("%s", dizi);
	ft_bzero(dizi, 12);
	printf("%s\n", dizi);
	printf("-------\n");
	bzero(dizi, 12);
	printf("-------\n");
} */

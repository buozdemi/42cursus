/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:43:46 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/28 17:18:54 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	benimfonk2(unsigned int i, char *p)
{
	if (i > -1)
		p[i] = p[i] - 32;
}
int	main(void)
{
	char dizi[15] = "makamaraci";

	ft_striteri(dizi, benimfonk2);
	printf("%s\n", dizi);
} */
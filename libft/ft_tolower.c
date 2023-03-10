/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:41:58 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:34:06 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	c = c + 32;
	return (c);
}
/* 
int	main(void)
{
	char	v;

	v = 'D';
	printf("%c\n", ft_tolower(v));
	printf("%c\n", tolower(v));
	return (0);
} */
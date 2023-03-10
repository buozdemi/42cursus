/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:09:57 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:46:43 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isascii(128));
	printf("%d\n", ft_isascii(126));
	printf("%d\n", isascii(128));
	printf("%d\n", isascii(126));
	return (0);
} */
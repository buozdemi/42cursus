/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:16:46 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:46:52 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isprint(9));
	printf("%d\n", ft_isprint(33));
	printf("%d\n", isprint(9));
	printf("%d\n", isprint(33));
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:20:31 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:31:25 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/* 
int	main(void)
{
	int	a;
	int	b;	

	a = 62;
	b = 65;
	printf("%d\n", ft_isalpha(a));
	printf("%d\n", isalpha(a));
	printf("%d\n", ft_isalpha(b));
	printf("%d\n", isalpha(b));
	return (0);
} */
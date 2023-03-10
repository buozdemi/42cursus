/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:42:36 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:31:31 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/* 
int	main(void)
{
	printf("%d\n", ft_isdigit(48));
	printf("%d\n", ft_isdigit(47));
	printf("%d\n", isdigit(48));
	printf("%d\n", isdigit(47));
	return (0);
}
 */
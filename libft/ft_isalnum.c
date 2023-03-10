/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:47:57 by buozdemi          #+#    #+#             */
/*   Updated: 2022/01/19 17:31:22 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || \
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/* 
int main(void)
{
	char c;
	char d;
	c = 'L';
	d = 'c';
	
	printf("%d\n",ft_isalnum(c));
	printf("%d\n",ft_isalnum(47));
	printf("%d\n",ft_isalnum(d));
	printf("%d\n",isalnum(c));
	printf("%d\n",isalnum(47));
	printf("%d\n",isalnum(d));
}	
 */
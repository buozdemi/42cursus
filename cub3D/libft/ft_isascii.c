/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:02:13 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:03:52 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/* 
int main()
{
	int a = ' ';
	int b = 130;
	printf("origin a: %d    b: %d\n", isascii(a), isascii(b));
	printf("test   a: %d    b:%d", ft_isascii(a), ft_isascii(b));	
	
	return(0);
}
 */

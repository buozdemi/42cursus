/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:03:59 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:44:29 by aoner            ###   ########.tr       */
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
int main()
{
	int a = 1, b = 73;
	printf("origin a:%d   b:%d\n", isprint(a), isprint(b));
	printf("test   a:%d   b:%d", ft_isprint(a), ft_isprint(b));
	
	
	return(0);
}
 */

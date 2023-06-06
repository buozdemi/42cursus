/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:02:53 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:40:57 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || \
			(c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
int main()
{
	int a = 59, b = 50, c= 173;
	
	printf("origin a: %d    b: %d    c: %d\n", isalnum(a), isalnum(b), isalnum(c));
	printf("test   a: %d    b: %d    c: %d\n", \
	ft_isalnum(a), ft_isalnum(b), ft_isalnum(c));
	
	return(0);
}
*/

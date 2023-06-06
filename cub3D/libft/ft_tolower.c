/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:24:06 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:51:57 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
int main()
{
	
	int a = 36 , b = 'B';
	printf("origin tolower a: %c b: %c\n", tolower(a), tolower(b));
	printf("test tolower a: %c   b: %c", ft_tolower(a), ft_tolower(b));
	
	return(0);
} */

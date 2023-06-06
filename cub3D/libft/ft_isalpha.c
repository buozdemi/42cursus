/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:02:24 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 12:57:03 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* 
int main()
{
	int a = 65, b = 64;
	
	
	printf("origin a: %d   b: %d\n", isalpha(a), isalpha(b));
	printf("test   a: %d   b: %d", ft_isalpha(a), ft_isalpha(b));

	
	return(0);
}
*/

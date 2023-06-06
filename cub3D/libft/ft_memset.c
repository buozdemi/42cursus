/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:06:17 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:31:40 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*C parametresi ile gösterilen karakteri (unsigned char),
dest parametresindeki ilk n parametre değeri kadar kopyalar*/
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}
/*
int main()
{
    char set[] = "nkadarkopya";
    
	printf("origin n-copy :%s\n", memset(set, 'x', 4));
	printf("test n- copy : %s", ft_memset(set,'x', 4));
    return(0);
}*/

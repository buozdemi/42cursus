/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:11:50 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:43:22 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p != NULL)
	{
		ft_bzero(p, (count * size));
		return (p);
	}
	return (NULL);
}
/*int main()
{
	int *ptr, i, n2, n1;
	
	n1 = 1;
	n2 = 3;
	ptr = (int*)ft_calloc(n2, sizeof(int));
	
	printf("Addresses of allocated memory:\n");
  	i = 0;
	while (i < n2) 
	{
		printf("%p\n", ptr + i);
		i++;
	}
   free(ptr);
   return(0);
}*/

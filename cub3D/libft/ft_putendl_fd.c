/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:11 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:00:08 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*‘s’ string çıktısını sonunda new line karakteri ile
birlikte verilen file descriptora yazar*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
/*
int main()
{
	char set[] = "newlinefd";
	ft_putendl_fd(set, 2);
	return(0);
	
	
}*/

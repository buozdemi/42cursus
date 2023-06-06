/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:34:36 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 14:07:14 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*Integer ‘n’ değerinin çıktısını verilen file
descriptora yazar*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{	
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
/*
int main()
{
	int c = -895;
	ft_putnbr_fd(c, 1);
	
	return(0);
}*/

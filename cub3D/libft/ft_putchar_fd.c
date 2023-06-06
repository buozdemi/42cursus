/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:33:17 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:58:35 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
/*programlamada kullanılan ve filelara erişimde kullanılan,
negatif değerler almayan integer değişkenler..
FD, open file of the process'i benzersiz şekilde tanımlayan 
tamsayıdır.her işlem için işletim sisteminde benzersiz bir 
file descriptors table bulunur.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main()
{
	char a = 'Z';
	ft_putchar_fd(a, 2);
	return(0);
}*/

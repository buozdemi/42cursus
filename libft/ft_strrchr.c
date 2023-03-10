/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:39:12 by buozdemi          #+#    #+#             */
/*   Updated: 2022/02/01 16:39:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len != -1)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
/*
	int	len;
	int	m;

	len = ft_strlen(str);
	m = len;
	while (((str[m]) != (unsigned char)c) && (m > 0))
		m--;
	if (str[m] == (unsigned char)c && (len >= 0))
		return ((char *)str + m); */
/* 
int	main(void)
{
	const char	dizi[] = "aslanbahisoynamaz";
	char	*p;
	char	*m;

	p = ft_strrchr(dizi, 'n');
	m = strrchr(dizi, 'n');
	printf("%s\n", p);
	printf("%s\n", m);
	return (0);
}  */
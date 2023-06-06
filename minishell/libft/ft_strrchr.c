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

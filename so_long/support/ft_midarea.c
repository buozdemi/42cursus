/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_midarea.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:21:02 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/05 17:48:04 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_midarea(char *s1)
{
	size_t	i;

	i = 0;
	while ((s1[i] == '0' || \
			s1[i] == '1' || \
			s1[i] == 'C' || \
			s1[i] == 'E' || \
			s1[i] == 'P'))
		i++;
	if (!s1[i])
		return (1);
	else
		return (0);
}
/* if (!s1 || !set)
		return (0);
	while (*s1 != '\n' && ft_strchrnew(set, *s1))
		s1++;
	if (s1 == NULL)
		return (1);
	return (0); */
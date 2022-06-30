/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:17:45 by buozdemi          #+#    #+#             */
/*   Updated: 2022/04/07 15:52:03 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t		tot_size;
	void		*dst;

	tot_size = size * count;
	dst = malloc(tot_size);
	if (!dst)
		return (0);
	ft_memset(dst, 0, tot_size);
	return (dst);
}

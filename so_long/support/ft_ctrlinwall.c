/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrlinwall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:04:10 by buozdemi          #+#    #+#             */
/*   Updated: 2022/06/11 13:52:47 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	ft_ctrlinwall(char *s1, char *set)
{
	size_t	i;

	if (ft_strchrnew(set, *s1))
	{
		i = ft_strlen(s1) - 1;
		if (ft_strchrnew(set, s1[i]))
			return (1);
	}
	return (0);
}

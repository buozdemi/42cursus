/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:20:27 by aoner             #+#    #+#             */
/*   Updated: 2022/12/23 13:31:45 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_rvstrncmp(const char *s1, const char *s2)
{
	int	i;
	int	k;
	int	m;

	i = ft_strlen(s1) - 1;
	m = ft_strlen(s1) - 1;
	k = ft_strlen(s2) - 1;
	while (i != m - 3 && (s1[i] && s2[k]) && (s1[i] == s2[k]))
	{	
		i--;
		k--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[k]);
}

void	map_name_ctrl(char **argv)
{
	if (ft_rvstrncmp(argv[1], ".cub") != 0)
	{
		printf("Error\nThe file named '.CUB' was not found!");
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:19:51 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 13:35:51 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	ft_cd(char **input)
{
	char	*home;

	errno = 0;
	if (input[1] != NULL)
	{
		if (chdir(input[1]) != 0)
		{
			perror("minish ");
			errno = 1;
		}
	}
	else
	{
		home = find_and_pull("HOME");
		if (chdir(home))
		{
			perror("minish ");
			errno = 1;
		}
		free(home);
	}
	if (!is_parent())
		exit (errno);
}

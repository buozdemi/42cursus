/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:23:58 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:45:36 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	ft_pwd(void)
{
	char	*result;

	errno = 0;
	result = getcwd((void *)0, 0);
	if (!result)
	{
		perror("minish ");
		errno = 1;
	}
	else
		printf("%s\n", result);
	free(result);
	if (!is_parent())
		exit(errno);
}

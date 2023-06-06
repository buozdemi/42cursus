/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:39:46 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:42:31 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	builtin_check(char *command)
{
	if (ft_strcmp(command, "cd"))
		return (CD);
	if (ft_strcmp(command, "env"))
		return (ENV);
	if (ft_strcmp(command, "pwd"))
		return (PWD);
	if (ft_strcmp(command, "echo"))
		return (ECHO);
	if (ft_strcmp(command, "exit"))
		return (EXIT);
	if (ft_strcmp(command, "unset"))
		return (UNSET);
	if (ft_strcmp(command, "export"))
		return (EXPORT);
	return (0);
}

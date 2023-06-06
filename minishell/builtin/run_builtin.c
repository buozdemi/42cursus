/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:59 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:44:32 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	run_builtin(char **execute)
{
	int	type;

	type = builtin_check(execute[0]);
	if (type == CD)
		ft_cd(execute);
	if (type == ENV)
		ft_env();
	if (type == PWD)
		ft_pwd();
	if (type == ECHO)
		ft_echo(execute);
	if (type == EXIT)
		ft_exit(execute);
	if (type == UNSET)
		ft_unset(execute);
	if (type == EXPORT)
		ft_export(execute);
}

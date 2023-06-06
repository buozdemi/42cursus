/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:52:17 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:49:24 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	env_len(void)
{
	char	**env;

	env = g_ms.envcopy;
	while (*env)
		env++;
	return (env - g_ms.envcopy);
}

int	export_len(void)
{
	char	**exp;

	exp = g_ms.expcopy;
	while (*exp)
		exp++;
	return (exp - g_ms.expcopy);
}

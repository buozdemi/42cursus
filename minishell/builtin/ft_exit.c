/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:29:26 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 17:00:46 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	exit_process_arg_count(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int	is_valid_arg_for_exit(char *arg)
{
	while (*arg)
	{
		if ((*arg >= '0' && *arg <= '9') || *arg == '+' || *arg == '-')
			arg++;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(char **input)
{
	if (exit_process_arg_count(input) == 1)
	{
		printf("exit\n");
		exit(errno);
	}
	else
	{
		if (is_valid_arg_for_exit(input[1]))
		{
			if (exit_process_arg_count(input) > 2)
			{
				write(2, "exit\nminishell: exit: too many arguments\n", 41);
				errno = 1;
				return ;
			}
			exit(ft_atoi(input[1]) % 256);
		}
		write(2, "exit\nminishell: exit: numeric argument required\n", 48);
		exit(-1 % 256);
	}
}

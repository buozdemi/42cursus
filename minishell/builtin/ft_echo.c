/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:26:02 by aoner             #+#    #+#             */
/*   Updated: 2022/11/15 21:17:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	put_char(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		write(1, &(input[i]), 1);
		i++;
	}
}

int	extra_option_check(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_strcmp(str[i], "-n"))
			i++;
		else
			break ;
	}
	return (i);
}

void	ft_echo(char **input)
{
	int	i;
	int	flag;

	errno = 0;
	i = 1;
	flag = 1;
	i = extra_option_check(input);
	if (i > 1)
		flag = 0;
	while (input[i])
	{
		put_char(input[i]);
		if (input[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (flag)
		write(1, "\n", 1);
	if (!is_parent())
		exit(EXIT_SUCCESS);
}

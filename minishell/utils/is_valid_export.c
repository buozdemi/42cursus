/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:50:41 by aoner             #+#    #+#             */
/*   Updated: 2022/11/16 15:47:23 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

int	all_other_signs(char c)
{
	return ((c >= 33 && c <= 47) || \
			(c >= 58 && c <= 60) || \
			(c >= 62 && c <= 64) || \
			(c >= 91 && c <= 96) || \
			(c >= 123 && c <= 126));
}

int	equal_sign_check(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && !all_other_signs(str[i]))
		i++;
	if (!str[i] || str[i] == '=')
		return (1);
	return (0);
}

int	is_valid_export(char *str)
{
	char	*head;

	if (!equal_sign_check(str))
		return (-2);
	head = ft_strchr(str, '=');
	if (!head)
		return (2);
	if (head == str)
		return (-2);
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_unset(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' || all_other_signs(str[i]))
		{
			wrong_char_export(str);
			return (0);
		}
		i++;
	}
	return (1);
}

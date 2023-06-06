/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_up_the_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:22:57 by aoner             #+#    #+#             */
/*   Updated: 2022/11/19 14:27:56 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

char	**push_array(char **arg_arr, char *str)
{
	int		i;
	int		len;
	char	**new_arr;

	i = 0;
	len = 0;
	while (arg_arr && arg_arr[len])
		len++;
	new_arr = ft_calloc(sizeof(char *), len + 2);
	while (i < len)
	{
		new_arr[i] = arg_arr[i];
		i++;
	}
	new_arr[i] = str;
	free(arg_arr);
	return (new_arr);
}

void	wr_free(void)
{
	free_token();
	free_process();
}

int	fix_up_the_arguments(t_token **token, t_process *process)
{
	char		*data;

	if ((*token)->type == STRING)
	{
		data = quotes_handle((*token)->str);
		process->execute = push_array(process->execute, data);
	}
	else
	{
		data = quotes_handle((*token)->str);
		process->redirs = push_array(process->redirs, data);
		*token = (*token)->next;
		if (!(*token) || (*token)->type != STRING)
		{
			wr_free();
			if (!(*token))
				token_err(0);
			else
				token_err((*token)->type);
			return (0);
		}
		data = quotes_handle((*token)->str);
		process->redirs = push_array(process->redirs, data);
	}
	return (1);
}

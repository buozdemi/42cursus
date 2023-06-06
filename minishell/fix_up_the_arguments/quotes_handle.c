/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:56:20 by aoner             #+#    #+#             */
/*   Updated: 2022/11/03 19:56:20 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

void	push_new_str(char **new_str, char *str)
{
	char	*tmp;

	if (!(*new_str))
	{
		*new_str = ft_strdup(str);
		free(str);
		return ;
	}
	tmp = *new_str;
	*new_str = ft_strjoin(*new_str, str);
	free(tmp);
	free(str);
}

static char	*get_str(char *str, int	*pos)
{
	int	first;

	first = *pos;
	while (str[*pos] && str[*pos] != '"' && str[*pos] != '\'')
		(*pos)++;
	return (ft_substr(str, first, *pos - first));
}

char	*clean_quote_with_type(char *str, int *pos, char type)
{
	int		first;
	char	*new_str;

	(*pos)++;
	first = *pos;
	while (str[*pos] && str[*pos] != type)
		(*pos)++;
	new_str = ft_substr(str, first, *pos - first);
	if (str[*pos])
		(*pos)++;
	return (new_str);
}

char	*quotes_handle(char *str)
{
	int		i;
	char	*data;
	char	*result;

	i = 0;
	result = NULL;
	str = is_there_dollar(str);
	while (str[i])
	{
		if (str[i] == '"')
			data = clean_quote_with_type(str, &i, '"');
		else if (str[i] == '\'')
			data = clean_quote_with_type(str, &i, '\'');
		else
			data = get_str(str, &i);
		push_new_str(&result, data);
	}
	free(str);
	return (result);
}

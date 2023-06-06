/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:00:25 by aoner             #+#    #+#             */
/*   Updated: 2022/11/03 15:00:25 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minish.h"

static char	*get_str(char *str, int	*pos, int type)
{
	int		first;
	char	*data;

	first = *pos;
	while (str[*pos] != type)
		(*pos)++;
	data = ft_substr(str, first, *pos - first);
	(*pos)++;
	return (data);
}

char	*replace_env_var(char *str)
{
	int		i;
	int		first;
	char	*env;
	char	*result;
	char	*data;

	i = 0;
	result = NULL;
	data = get_str(str, &i, '$');
	push_new_str(&result, data);
	first = i;
	if (str[i] == '?' && ++i)
		push_new_str(&result, ft_itoa(errno));
	else
	{
		while (valid_char(str[i]))
			(i)++;
		data = ft_substr(str, first, i - first);
		env = find_and_pull(data);
		push_new_str(&result, env);
		free(data);
	}
	data = get_str(str, &i, 0);
	push_new_str(&result, data);
	return (result);
}

int	valid_char(char c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c >= '0' && c <= '9') || \
			(c == '_') || (c == '?'));
}

int	is_it_dollar_cmd(char *str)
{
	int		i;
	int		valid;
	int		invalid;

	i = 0;
	valid = 1;
	invalid = 0;
	while (str[i] && str[i] != '$')
	{
		if (str[i] == '\'')
			valid = invalid;
		if (str[i] == '"')
			invalid = !invalid;
		i++;
	}
	if (!valid_char(*(ft_strchr(str, '$') + 1)))
		return (0);
	return (valid);
}

char	*is_there_dollar(char *str)
{
	char	*tmp;
	char	*new_str;

	new_str = ft_strdup(str);
	while (ft_strchr(new_str, '$') && is_it_dollar_cmd(new_str))
	{
		tmp = new_str;
		new_str = replace_env_var(new_str);
		free(tmp);
	}
	return (new_str);
}

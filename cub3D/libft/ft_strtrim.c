/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:31:31 by aoner             #+#    #+#             */
/*   Updated: 2022/02/04 13:53:23 by aoner            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*newstr;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (k >= 0 && ft_strchr(set, s1[k]))
		k--;
	newstr = ft_substr(s1, i, (k - i + 1));
	return (newstr);
}

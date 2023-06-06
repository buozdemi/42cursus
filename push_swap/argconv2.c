/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argconv2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:53:52 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/13 14:34:41 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	convonlydigit(char *s, t_allnum *allnum)
{
	int	c;
	int	g;

	g = 0;
	c = 0;
	if (ft_atoi(s, allnum) == 0 && s[c] == '0' && s[c + 1] == '\0')
	{
		samenumber(ft_atoi(s, allnum), allnum);
		allnum->a[allnum->m - 1] = 0;
	}
	else
	{
		samenumber(ft_atoi(s, allnum), allnum);
		allnum->a[allnum->m - 1] = ft_atoi(s, allnum);
	}
	--allnum->m;
}

void	spacedigit(char *s, t_allnum *allnum)
{
	int		c;
	int		i;
	char	**returnsplit;

	c = 0;
	i = 0;
	returnsplit = ft_split(s, ' ');
	while (returnsplit[c] != NULL)
	{
		samenumber(ft_atoi(returnsplit[c], allnum), allnum);
		allnum->a[allnum->m - 1] = ft_atoi(returnsplit[c], allnum);
		--allnum->m;
		c++;
	}
	while (returnsplit[i])
		free(returnsplit[i++]);
	free(returnsplit);
}

int	digitordigits(char **argv, int i)
{
	int	c;

	c = 0;
	while (argv[i][c] != '\0')
	{
		if (ft_whichdigit(argv[i][c]) == 2)
			return (2);
		c++;
	}
	return (1);
}

void	rrrab(t_allnum *allnum)
{
	allnum->info = 1;
	reverserotatea(allnum);
	allnum->info = 1;
	reverserotateb(allnum);
	ft_printf("rrr\n");
}

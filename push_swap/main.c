/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:23:14 by buozdemi          #+#    #+#             */
/*   Updated: 2022/05/14 18:25:16 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_allnum	*allnum;

	(void)argc;
	allnum = ft_calloc(sizeof(t_allnum), 1);
	if (!allnum)
		exit(1);
	if (maintheme(allnum, argv) == 0)
	{
		free(allnum->a);
		free(allnum);
		exit(1);
	}
	if (allnum->intnumbersa <= 6)
		minialgorithm(allnum);
	else if (allnum->intnumbersa <= 161)
		smallgorithm(allnum);
	else
		radixalgorithm(allnum);
	secondpartfree(allnum);
}

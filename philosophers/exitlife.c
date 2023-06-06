/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitlife.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:44:26 by buozdemi          #+#    #+#             */
/*   Updated: 2022/09/05 15:42:18 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	joinlife(t_philo **master)
{
	int	ph_num;
	int	i;

	i = 0;
	ph_num = master[i]->ph_num;
	while (i < ph_num)
	{
		pthread_join(master[i]->tid, NULL);
		i++;
	}
}

void	exitfunc(t_philo **master, t_died *rule, t_mutex *singlemutex, int j)
{
	int	i;

	i = -1;
	if (j == 1)
	{
		while (++i < rule->ph_num)
			pthread_mutex_destroy(&singlemutex->forks[i]);
	}
	pthread_mutex_destroy(&singlemutex->mealmutex);
	pthread_mutex_destroy(&singlemutex->diedmutex);
	pthread_mutex_destroy(&singlemutex->timemutex);
	pthread_mutex_destroy(&singlemutex->allatemutex);
	if (singlemutex->forks)
		free(singlemutex->forks);
	i = 0;
	while (master[i])
		free(master[i++]);
	free(master);
}

void	earlyexitfunc(t_philo **master)
{
	int	i;

	i = 0;
	while (master[i])
		free(master[i++]);
	free(master);
}

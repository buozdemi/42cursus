/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifeutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:07:49 by buozdemi          #+#    #+#             */
/*   Updated: 2022/09/07 14:42:47 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	dualphilocreate(t_philo **master, int first_time, int ph_num)
{
	int	i;

	i = 0;
	while (i < ph_num)
	{
		master[i]->first_time = first_time;
		master[i]->last_meal = first_time;
		if (pthread_create(&master[i]->tid, NULL, life, master[i]))
		{
			printf("Error\nThere was an error creating the threads\n");
			return (1);
		}
		i = i + 2;
	}
	return (0);
}

int	singlephilocreate(t_philo **master, int first_time, int ph_num)
{
	int	i;

	i = 1;
	while (i < ph_num)
	{
		master[i]->first_time = first_time;
		master[i]->last_meal = first_time;
		if (pthread_create(&master[i]->tid, NULL, life, master[i]))
		{
			printf("Error\nThere was an error creating the threads\n");
			return (1);
		}
		i = i + 2;
	}
	return (0);
}

int	am_i_dead(t_philo *ph)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&ph->othermutex->timemutex);
	ret = (unsigned int)ph->time_die <= time_in_ml() - ph->last_meal;
	pthread_mutex_unlock(&ph->othermutex->timemutex);
	return (ret);
}

void	i_ate(t_philo *ph)
{
	pthread_mutex_lock(&ph->othermutex->mealmutex);
	ph->serv_count++;
	ph->othermutex->all_serv_count++;
	pthread_mutex_unlock(&ph->othermutex->mealmutex);
}

void	update_mealtime(t_philo *ph)
{
	pthread_mutex_lock(&ph->othermutex->timemutex);
	ph->last_meal = time_in_ml();
	pthread_mutex_unlock(&ph->othermutex->timemutex);
}

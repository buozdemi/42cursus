/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:52:41 by buozdemi          #+#    #+#             */
/*   Updated: 2022/09/05 16:09:21 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

unsigned int	time_in_ml(void)
{
	struct timeval	tv;
	unsigned int	ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

unsigned int	the_counter(unsigned int old)
{
	return (time_in_ml() - old);
}

void	ft_sleepe(t_philo *ph)
{
	unsigned int	start;

	start = time_in_ml();
	pthread_mutex_lock(&(ph->othermutex->diedmutex));
	if (!(*(ph->died)))
	{
		pthread_mutex_unlock(&(ph->othermutex->diedmutex));
		while (time_in_ml() < start + ph->time_eat)
			usleep(50);
	}
	else
		pthread_mutex_unlock(&(ph->othermutex->diedmutex));
}

void	ft_sleeps(t_philo *ph)
{
	unsigned int	start;

	start = time_in_ml();
	pthread_mutex_lock(&(ph->othermutex->diedmutex));
	if (!(*(ph->died)))
	{
		pthread_mutex_unlock(&(ph->othermutex->diedmutex));
		while (time_in_ml() < start + ph->time_sleep)
			usleep(50);
	}
	else
		pthread_mutex_unlock(&(ph->othermutex->diedmutex));
}

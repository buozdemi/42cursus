/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:33:57 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 17:15:06 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	author(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->othermutex->diedmutex);
	if (!(*ph->died))
		printf("%u %d %s\n", the_counter(ph->first_time), ph->id + 1, msg);
	pthread_mutex_unlock(&ph->othermutex->diedmutex);
}

int	is_satiate(t_philo *ph)
{
	int	ret;

	ret = (ph->serv_count == ph->my_target_meal);
	return (ret);
}

int	is_dead(t_philo *ph)
{
	int	ret;

	pthread_mutex_lock(&ph->othermutex->diedmutex);
	ret = *ph->died;
	pthread_mutex_unlock(&ph->othermutex->diedmutex);
	return (ret);
}

void	*life(void *philovoid)
{
	t_philo	*ph;

	ph = (t_philo *)philovoid;
	while (!(is_dead(ph)) && !is_satiate(ph))
	{
		pthread_mutex_lock(ph->left_fork);
		author(ph, "has taken a fork");
		if (ph->right_fork == NULL)
			break ;
		pthread_mutex_lock(ph->right_fork);
		author(ph, "has taken a fork");
		author(ph, "is eating");
		update_mealtime(ph);
		ft_sleepe(ph);
		i_ate(ph);
		pthread_mutex_unlock(ph->left_fork);
		pthread_mutex_unlock(ph->right_fork);
		author(ph, "is sleeping");
		ft_sleeps(ph);
		author(ph, "is thinking");
	}
	return (0);
}

int	createlife(t_philo **master, int first_time)
{
	int	ph_num;

	ph_num = master[0]->ph_num;
	if (dualphilocreate(master, first_time, ph_num))
		return (1);
	usleep(100);
	if (singlephilocreate(master, first_time, ph_num))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:21:21 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 17:17:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	createmutex(t_philo **master, t_mutex *singlemutex)
{
	int	i;

	i = -1;
	while (++i < master[0]->ph_num)
	{
		if (pthread_mutex_init(&singlemutex->forks[i], NULL))
		{
			printf("Error\nMutex init problems.\n");
			return (1);
		}
	}
	i = -1;
	while (++i < master[0]->ph_num)
	{
		master[i]->left_fork = &singlemutex->forks[i];
		master[i]->right_fork = NULL;
		if (master[1])
		{
			master[i]->right_fork = &singlemutex->forks[(i + 1) \
			% master[0]->ph_num];
		}
		master[i]->othermutex = singlemutex;
	}
	return (0);
}

int	fillrule(t_died *rule, char **argv)
{
	rule->died = 0;
	rule->ph_num = ft_atoi(argv[1]);
	return (0);
}

void	fivearguman(t_philo **master, char **argv)
{
	int	ph_num;
	int	i;

	i = 0;
	ph_num = ft_atoi(argv[1]);
	while (i < ph_num)
	{
		if (argv[5])
		{
			master[i]->my_target_meal = ft_atoi(argv[5]);
		}
		i++;
	}
}

int	fillvalue(t_philo **master, char **argv, t_died *rule)
{
	int	i;

	i = 0;
	fillrule(rule, argv);
	while (i < ft_atoi(argv[1]))
	{
		master[i] = (t_philo *)ft_calloc(sizeof(t_philo), 1);
		if (!master[i])
		{
			printf("Error\nMalloc data problems.\n");
			return (1);
		}
		master[i]->id = i;
		master[i]->ph_num = ft_atoi(argv[1]);
		master[i]->time_die = ft_atoi(argv[2]);
		master[i]->time_eat = ft_atoi(argv[3]);
		master[i]->time_sleep = ft_atoi(argv[4]);
		master[i]->my_target_meal = -1;
		master[i]->serv_count = 0;
		master[i]->died = &rule->died;
		i++;
	}
	fivearguman(master, argv);
	return (0);
}

int	fillsinglemutex(t_philo **master, t_died *rule, t_mutex *singlemutex)
{
	if (pthread_mutex_init(&(singlemutex->mealmutex), NULL) || \
	pthread_mutex_init(&(singlemutex->diedmutex), NULL) || \
	pthread_mutex_init(&(singlemutex->timemutex), NULL) || \
	pthread_mutex_init(&(singlemutex->allatemutex), NULL))
	{
		printf("Error\nMutex init problems.\n");
		exitfunc(master, rule, singlemutex, 0);
		return (1);
	}
	singlemutex->all_serv_count = 0;
	singlemutex->all_ate = 0;
	singlemutex->target_meal = master[0]->my_target_meal * master[0]->ph_num;
	singlemutex->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), \
	master[0]->ph_num);
	if (!(singlemutex->forks))
	{
		printf("Error\nMalloc data problems.\n");
		exitfunc(master, rule, singlemutex, 0);
		return (1);
	}
	return (0);
}

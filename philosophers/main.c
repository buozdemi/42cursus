/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:50:59 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 17:28:54 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	everyone_satiate(t_mutex *singlemutex)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&singlemutex->mealmutex);
	ret = singlemutex->all_serv_count == singlemutex->target_meal;
	pthread_mutex_unlock(&singlemutex->mealmutex);
	return (ret);
}

void	if_am_i_dead(t_philo **master, t_died *rule, \
t_mutex *singlemutex, int i)
{
	int	ph_num;

	ph_num = rule->ph_num;
	pthread_mutex_lock(&singlemutex->diedmutex);
	rule->died = 1;
	pthread_mutex_unlock(&singlemutex->diedmutex);
	printf("%u %d died\n", the_counter(master[i]->first_time), \
	(master[i]->id % ph_num) + 1);
}

void	death_control(t_philo **master, t_died *rule, t_mutex *singlemutex)
{
	int	i;
	int	ph_num;
	int	c;

	c = 0;
	ph_num = rule->ph_num;
	while (!everyone_satiate(singlemutex))
	{
		i = 0;
		while (i < ph_num)
		{
			if (everyone_satiate(singlemutex) || is_dead(master[i]))
			{
				c = 1;
				break ;
			}
			if (am_i_dead(master[i]))
				if_am_i_dead(master, rule, singlemutex, i);
			i++;
			usleep(100);
		}
		if (c == 1)
			break ;
	}
}

int	maindivide(t_philo **master, char **argv, \
t_died *rule, t_mutex *singlemutex)
{
	if (fillvalue(master, argv, rule))
	{
		earlyexitfunc(master);
		return (1);
	}
	if (fillsinglemutex(master, rule, singlemutex))
		return (1);
	if (createmutex(master, singlemutex))
	{
		exitfunc(master, rule, singlemutex, 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo		**master;
	t_died		rule;
	t_mutex		singlemutex;
	int			first_time;

	if (argvcontrol(argc, argv))
		return (0);
	master = (t_philo **)ft_calloc(sizeof(t_philo *), (ft_atoi(argv[1]) + 1));
	if (!master)
	{
		printf("Error\nMalloc data problems.");
		return (0);
	}
	if (maindivide(master, argv, &rule, &singlemutex))
		return (0);
	first_time = time_in_ml();
	if (createlife(master, first_time))
	{
		exitfunc(master, &rule, &singlemutex, 1);
		return (0);
	}
	death_control(master, &rule, &singlemutex);
	joinlife(master);
	exitfunc(master, &rule, &singlemutex, 1);
	return (0);
}

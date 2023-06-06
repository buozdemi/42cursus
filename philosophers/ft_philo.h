/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:43:35 by buozdemi          #+#    #+#             */
/*   Updated: 2022/09/05 16:09:34 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo
{
	int				id;
	int				ph_num;
	unsigned int	first_time;
	unsigned int	last_meal;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				my_target_meal;
	int				serv_count;
	int				*died;
	pthread_t		tid;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_mutex	*othermutex;
}	t_philo;

//rule
typedef struct s_died
{
	int	ph_num;
	int	died;
}	t_died;

//singlemutex
typedef struct s_mutex
{
	int				target_meal;
	int				all_serv_count;
	int				all_ate;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mealmutex;
	pthread_mutex_t	diedmutex;
	pthread_mutex_t	timemutex;
	pthread_mutex_t	allatemutex;
}	t_mutex;

int				argvcontrol(int argc, char **argv);
int				fillvalue(t_philo **master, char **argv, t_died *rule);
int				createmutex(t_philo **master, t_mutex *singlemutex);
int				createlife(t_philo **master, int first_time);
unsigned int	time_in_ml(void);
unsigned int	the_counter(unsigned int old);
void			ft_sleeps(t_philo *ph);
void			ft_sleepe(t_philo *ph);
void			exitlife(t_philo **master);
int				ft_atoi(const char *str);
void			joinlife(t_philo **master);
int				onlynum(char **argv); //Buraya yazmana gerek yok.
int				fillsinglemutex(t_philo **master, \
t_died *rule, t_mutex *singlemutex);
void			*life(void *philovoid);
int				dualphilocreate(t_philo **master, int first_time, int ph_num);
int				singlephilocreate(t_philo **master, int first_time, int ph_num);
int				is_dead(t_philo *ph);
void			author(t_philo *ph, char *msg);
int				am_i_dead(t_philo *ph);
void			update_mealtime(t_philo *ph);
void			i_ate(t_philo *ph);
void			exitfunc(t_philo **master, t_died *rule, \
t_mutex *singlemutex, int j);
int				everyone_satiate(t_mutex *singlemutex);
int				maindivide(t_philo **master, char **argv, \
t_died *rule, t_mutex *singlemutex);
void			change1died(t_mutex *singlemutex, t_died *rule);
void			change1allate(t_mutex *singlemutex);
void			earlyexitfunc(t_philo **master);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);

#endif
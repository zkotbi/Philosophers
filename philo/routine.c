/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:33:59 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/25 22:24:45 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int get_dinner_statue(t_philo *philo)
{
	int statue;

	statue = 0;
	pthread_mutex_lock(&philo->table->stop_mtx);
	statue = philo->table->is_dinner_stop;
	pthread_mutex_unlock(&philo->table->stop_mtx);
	return (statue);
}

int get_all_ready(t_philo	*philo)
{
	int val;

	pthread_mutex_lock(&philo->table->start);
	val = philo->table->is_all_ready;
	pthread_mutex_unlock(&philo->table->start);
	return (val);
}

time_t get_last_meal_time(t_philo *philo)
{
	time_t time;

	pthread_mutex_lock(&philo->time_mtx);
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->time_mtx);
	return (time);
}

enum e_state get_philo_state(t_philo	*philo)
{
	enum e_state state;

	pthread_mutex_lock(&philo->state_mtx);
	state = philo->state;
	pthread_mutex_unlock(&philo->state_mtx);
	return (state);
}

void	write_state(time_t	time, t_wr_flags state, t_philo *philo)
{
	if (get_dinner_statue(philo) == 0 && state != WR_DIED)
		return ;
	pthread_mutex_lock(&(philo->table->write_mtx));
	if (state == TAKE_FORK)
		printf("%ld %d has taken a fork\n", time, philo->id + 1);
	if (state == WR_DIED)
		printf("%ld %d died\n", time, philo->id + 1);
	if (state == EATING)
		printf("%ld %d is eating\n", time, philo->id + 1);
	if (state == THINKING)
		printf("%ld %d is thinking\n", time, philo->id + 1);
	if (state == SLEEPING)
		printf("%ld %d is sleeping\n", time, philo->id + 1);
	pthread_mutex_unlock(&(philo->table->write_mtx));
}

static void	philo_activity(t_philo	*philo)
{
	while (get_dinner_statue(philo) == 1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}

static void	one_philo_activity(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[0]);
	write_state((get_time() - philo->table->philo_start), TAKE_FORK, philo);
	pthread_mutex_unlock(&philo->table->forks[0]);
}

void	*philo_routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if (philo->table->nb_forks == 1)
		one_philo_activity(philo);
	else
		philo_activity(philo);
	return (NULL);
}

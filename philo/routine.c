/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:34:54 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/20 06:53:22 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <sys/_types/_timeval.h>
#include <sys/time.h>
#include <time.h>

void write_state(time_t	time, t_wr_flags state, int id)
{
	if (state == TAKE_FORK)
		printf("%ld %d has taken a fork\n", time, id);
	if (state == WR_DIED)
		printf("%ld %d died\n", time, id);
	if (state == EATING)
		printf("%ld %d is eating\n", time, id);
	if (state == THINKING)
		printf("%ld %d is thinking\n", time, id);
	if (state == SLEEPING)
		printf("%ld %d is sleeping\n", time, id);
}

time_t get_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mtx[philo->l_fork]);
	write_state(time_t time, t_wr_flags state, int id)	
}

void philo_activity(t_philo	*philo)
{
	philo->philo_start = get_time();
	while (philo->state != FULL)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
void *philo_routine(void *var)
{
	t_philo *philo;

	philo = (t_philo *)var;
	philo_activity(philo);
	return (NULL);
}

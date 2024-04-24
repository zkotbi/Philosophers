/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:33:59 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/24 00:06:32 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_state(time_t	time, t_wr_flags state, t_philo *philo)
{
	if (philo->table->is_dinner_stop == 0 && state != WR_DIED)
		return ;
	pthread_mutex_lock(&(philo->table->write_mtx));
	if (philo->table->is_dinner_stop == 0 && state != WR_DIED
		&& !pthread_mutex_unlock(&philo->table->write_mtx))
		return ;
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
	while (philo->table->is_dinner_stop == 1)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:26:05 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/23 23:49:19 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	if (philo->table->is_dinner_stop == 0)
		return ;
	pthread_mutex_lock(&(philo->table->forks[philo->first_fork]));
	write_state((get_time() - philo->table->philo_start), TAKE_FORK, philo);
	if (philo->table->is_dinner_stop == 0
		&& !pthread_mutex_unlock(&(philo->table->forks[philo->first_fork])))
		return ;
	pthread_mutex_lock(&(philo->table->forks[philo->second_fork]));
	write_state((get_time() - philo->table->philo_start), TAKE_FORK, philo);
	write_state(get_time() - philo->table->philo_start, EATING, philo);
	philo->last_meal_time = get_time();
	ft_sleep(philo, philo->table->time_to_eat);
	philo->nb_time_eat++;
	if (philo->nb_time_eat == philo->table->nb_time_must_eat)
		set_philo_state(philo, FULL);
	pthread_mutex_unlock(&(philo->table->forks[philo->second_fork]));
	pthread_mutex_unlock(&(philo->table->forks[philo->first_fork]));
}

void	sleeping(t_philo	*philo)
{
	write_state(get_time() - philo->table->philo_start, SLEEPING, philo);
	ft_sleep(philo, philo->table->time_to_sleep);
}

void	thinking(t_philo	*philo)
{
	write_state(get_time() - philo->table->philo_start, THINKING, philo);
	ft_sleep(philo, get_thinking_time(philo->table));
}

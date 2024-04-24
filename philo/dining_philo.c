/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:04:54 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/24 00:05:00 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_thread(t_philo *philo)
{
	int	i;

	i = 0;
	philo->table->philo_start = get_time();
	while (i < philo->table->nb_forks)
	{
		philo[i].last_meal_time = philo->table->philo_start;
		if (pthread_create(&(philo[i].thread), NULL,
				&philo_routine, &philo[i]) != 0)
			return (thread_create_error(philo, i));
		i++;
	}
	return (1);
}

static void	join_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->nb_forks)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

static int	init_mutexs(t_philo *philo)
{
	int	i;

	philo->table->forks = malloc(sizeof(pthread_mutex_t)
			* philo->table->nb_forks);
	if (philo->table->forks == NULL)
		return (0);
	i = 0;
	while (i < philo->table->nb_forks)
	{
		if (pthread_mutex_init(&(philo->table->forks[i]), NULL) != 0)
			return (mutex_destroy(philo, i));
		if (pthread_mutex_init(&(philo[i].state_mtx), NULL) != 0)
			return (mutex_destroy(philo, i));
		i++;
	}
	if (pthread_mutex_init(&(philo->table->write_mtx), NULL) != 0)
		return (mutex_destroy(philo, i));
	return (1);
}

int	dining_philo(t_philo *philo)
{
	pthread_t	hv_th;

	if (init_mutexs(philo) == 0)
		return (0);
	if (start_thread(philo) == 0)
		return (mutex_destroy(philo, philo->table->nb_forks));
	if (pthread_create(&hv_th, NULL, &superviser, (void *)philo) != 0)
		return (thread_create_error(philo, philo->table->nb_forks),
			mutex_destroy(philo, philo->table->nb_forks));
	join_thread(philo);
	pthread_join(hv_th, NULL);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:31:06 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/19 23:39:29 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

int thread_create_error(t_philo *philo, int size)
{
	int it;

	it = 0;
	while (it < size)
	{
		pthread_detach(philo[it].thread);
		it++;
	}
	return (0);
}

int mutex_init_error(t_table	*table, int size)
{
	int it;

	it = 0;
	while (it < size)
	{
		pthread_mutex_destroy(&table->mtx[it]);
		it++;
	}
	return (0);
}

int init_philo_thread(t_philo	*philo)
{
	int i;

	i = 0;
	while (i < philo->table->nb_forks)
	{
		if (pthread_create(&(philo[i].thread), NULL, &philo_routine, &philo[i]) == 0)
			return (thread_create_error(philo, i));
		i++;
	}
	return (1);
}

int init_mutexs(t_table *table)
{
	int i;

	i = 0;
	while (i < table->nb_forks)
	{
		if (pthread_mutex_init(&(table->mtx[i]), NULL) != 0)
			return (mutex_init_error(table, i));
		i++;
	}
	return (1);
}

int dining_philo(t_philo *philo)
{
	if (init_mutexs(philo->table) == 0)
		return (0);
	if (init_philo_thread(philo) == 0)
		return (0);
	return (1);
}

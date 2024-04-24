/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:04:18 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/24 00:04:22 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_ptr(void	**ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

void	*free_philo(t_philo *philo)
{
	free_ptr((void **)&(philo->table));
	free_ptr((void **)&philo);
	return (NULL);
}

int	thread_create_error(t_philo *philo, int size)
{
	int	it;

	it = 0;
	while (it < size)
	{
		pthread_detach(philo[it].thread);
		it++;
	}
	return (0);
}

int	mutex_destroy(t_philo *philo, int size)
{
	int	it;

	it = 0;
	while (it < size)
	{
		pthread_mutex_destroy(&philo->table->forks[it]);
		pthread_mutex_destroy(&philo[it].state_mtx);
		it++;
	}
	return (0);
}

void	destroy_philos(t_philo	*philo)
{
	thread_create_error(philo, philo->table->nb_forks);
	mutex_destroy(philo, philo->table->nb_forks);
	pthread_mutex_destroy(&philo->table->write_mtx);
	free_ptr((void **)&(philo->table->forks));
	free_philo(philo);
}

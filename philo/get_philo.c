/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:38:49 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/26 08:43:35 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_dinner_statue(t_philo *philo)
{
	int	statue;

	statue = 0;
	pthread_mutex_lock(&philo->table->stop_mtx);
	statue = philo->table->is_dinner_stop;
	pthread_mutex_unlock(&philo->table->stop_mtx);
	return (statue);
}

time_t	get_last_meal_time(t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->time_mtx);
	time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->time_mtx);
	return (time);
}

enum e_state	get_philo_state(t_philo	*philo)
{
	enum e_state	state;

	pthread_mutex_lock(&philo->state_mtx);
	state = philo->state;
	pthread_mutex_unlock(&philo->state_mtx);
	return (state);
}

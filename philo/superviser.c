/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:03:02 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/26 08:50:28 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->state_mtx);
	if (state == DIED)
		philo->state = DIED;
	else if (state == FULL)
		philo->state = FULL;
	else if (state == NORM)
		philo->state = NORM;
	pthread_mutex_unlock(&philo->state_mtx);
}

static void	set_dinner_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->stop_mtx);
	philo->table->is_dinner_stop = 0;
	pthread_mutex_unlock(&philo->table->stop_mtx);
}

static void	check_philo_state(t_philo *philo)
{
	int		i;
	int		j;
	time_t	time;

	i = 0;
	j = 0;
	while (i < philo->table->nb_forks)
	{
		time = get_time();
		if ((time - get_last_meal_time(&philo[i]))
			>= philo[i].table->time_to_die)
		{
			set_philo_state(&philo[i], DIED);
			set_dinner_stop(philo);
			write_state(time - philo->table->philo_start,
				WR_DIED, &philo[i]);
			return ;
		}
		if (get_philo_state(&philo[i]) == FULL)
			j++;
		i++;
	}
	if (j == philo->table->nb_forks)
		set_dinner_stop(philo);
}

void	*superviser(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	while (1)
	{
		check_philo_state(philo);
		if (get_dinner_statue(philo) == 0)
			return (NULL);
	}
	return (NULL);
}

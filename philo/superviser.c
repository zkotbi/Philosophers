/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   superviser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:03:02 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/24 00:03:05 by zkotbi           ###   ########.fr       */
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

static void	check_philo_state(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < philo->table->nb_forks)
	{
		if ((get_time() - philo[i].last_meal_time)
			>= philo[i].table->time_to_die)
		{
			set_philo_state(&philo[i], DIED);
			philo->table->is_dinner_stop = 0;
			write_state(get_time() - philo->table->philo_start,
				WR_DIED, &philo[i]);
			return ;
		}
		if (philo[i].state == FULL)
			j++;
		i++;
	}
	if (j == philo->table->nb_forks)
		philo->table->is_dinner_stop = 0;
}

void	*superviser(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	while (1)
	{
		check_philo_state(philo);
		if (philo->table->is_dinner_stop == 0)
			break ;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:28:27 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/26 08:31:22 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

time_t	get_thinking_time(t_table *table)
{
	if (table->time_to_sleep + table->time_to_sleep > table->time_to_die
		|| (table->nb_forks % 2 == 0))
		return (0);
	return ((2 * table->time_to_eat - table->time_to_sleep) * 0.6);
}

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(t_philo *philo, time_t time)
{
	time_t	start;

	if (time == 0)
	{
		usleep(100);
		return ;
	}
	start = get_time();
	while (get_time() - start < time)
	{
		if (get_dinner_statue(philo) == 0)
			break ;
		usleep(50);
	}
}

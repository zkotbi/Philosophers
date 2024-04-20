/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:32:22 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/19 23:06:03 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static t_table *init_table(char **argv)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	table->nb_forks = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		table->nb_time_must_eat = ft_atoi(argv[5]);
	else
		table->nb_time_must_eat = -1;
	return (table);
}

static void assign_forks(t_philo philo)
{
	philo.r_fork = philo.id;
	if (philo.id != (philo.table->nb_forks -1))
		philo.l_fork = philo.id + 1;
	else 
		philo.l_fork = 0;
}

t_philo *init_philo(char **argv)
{
	t_philo *philo;
	t_table *table;
	int i;

	i = 0;
	table = init_table(argv);
	if (table == NULL)
		return (NULL);
	philo = malloc(sizeof(t_philo) * table->nb_forks);
	if (philo == NULL)
		return (free_philo(philo));
	while(i < table->nb_forks)
	{
		philo[i].table = table;
		philo[i].id = i;
		assign_forks(philo[i]);
		i++;
	}
	return (philo);
}

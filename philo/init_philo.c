/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:04:00 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/24 22:40:09 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_table	*init_table(char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (NULL);
	table->nb_forks = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->nb_time_must_eat = -1;
	table->is_dinner_stop = 1;
	table->is_all_ready = 0;
	if (argv[5] != NULL)
		table->nb_time_must_eat = ft_atoi(argv[5]);
	return (table);
}

static void	assign_forks(t_philo *philo)
{
	philo->first_fork = (philo->id + 1) % philo->table->nb_forks;
	philo->second_fork = philo->id;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = philo->id;
		philo->second_fork = (philo->id + 1) % philo->table->nb_forks;
	}
}

t_philo	*init_philo(char **argv)
{
	t_philo	*philo;
	t_table	*table;
	int		i;

	i = 0;
	table = init_table(argv);
	if (table == NULL)
		return (NULL);
	philo = malloc(sizeof(t_philo) * table->nb_forks);
	if (philo == NULL)
		return (free_philo(philo));
	while (i < table->nb_forks)
	{
		philo[i].table = table;
		philo[i].id = i;
		philo[i].nb_time_eat = 0;
		philo[i].state = NORM;
		philo[i].all_ready = 0;
		assign_forks(&philo[i]);
		i++;
	}
	return (philo);
}

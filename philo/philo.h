/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:21:36 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/20 03:21:01 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>

typedef enum e_wr_flags {
	TAKE_FORK,
	WR_DIED,
	EATING,
	THINKING,
	SLEEPING,
}	t_wr_flags ;

typedef enum e_state {
	DIED,
	FULL,
	NORM,
}	t_state ;

typedef struct s_table {
	time_t time_to_eat;
	time_t time_to_sleep;
	time_t time_to_die;
	time_t nb_forks;
	pthread_mutex_t *mtx;
	int nb_time_must_eat;
}	t_table;

typedef struct s_philo {
	pthread_t thread;
	t_table *table;
	int id;
	int l_fork;
	int r_fork;
	t_state	state;
	time_t last_meal_time;
	time_t philo_start;
	int nb_time_eat;
}	t_philo;

int			is_valid_input(char **argv);
t_philo		*init_philo(char **argv);
long		ft_atoi(const char *str);
void		*free_philo(t_philo *philo);
void		*free_ptr(void	**ptr);
int			dining_philo(t_philo *philo);
void		*philo_routine(void *var);

#endif

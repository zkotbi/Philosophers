/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:06:09 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/25 22:35:40 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/_pthread/_pthread_t.h>
# include <sys/time.h>
# include <pthread.h>
# include <time.h>
# include <unistd.h>

typedef enum e_wr_flags
{
	TAKE_FORK,
	WR_DIED,
	EATING,
	THINKING,
	SLEEPING,
}	t_wr_flags;

typedef enum e_state
{
	DIED,
	FULL,
	NORM,
}	t_state;

typedef struct s_table
{
	int				is_dinner_stop;
	int				is_all_ready;
	int				nb_forks;
	int				nb_time_must_eat;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			time_to_die;
	time_t			philo_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mtx;
	pthread_mutex_t	stop_mtx;
	pthread_mutex_t start;

}	t_table;

typedef struct s_philo
{
	int				id;
	int				first_fork;
	int				second_fork;
	int				is_dinner_stop;
	int				nb_time_eat;
	t_table			*table;
	t_state			state;
	pthread_t		thread;
	time_t			last_meal_time;
	pthread_mutex_t	state_mtx;
	pthread_mutex_t	stop_mtx;
	pthread_mutex_t	time_mtx;
}	t_philo;

int				is_valid_input(char **argv);
int				dining_philo(t_philo *philo);
int				mutex_destroy(t_philo *philo, int size);
int				thread_create_error(t_philo *philo, int size);
int				get_dinner_statue(t_philo *philo);
int				get_all_ready(t_philo	*philo);
long			ft_atoi(const char *str);
void			*free_philo(t_philo *philo);
void			*free_ptr(void	**ptr);
void			*philo_routine(void *var);
void			*superviser(void *var);
void			write_state(time_t	time, t_wr_flags state, t_philo *philo);
void			set_philo_state(t_philo *philo, t_state state);
void			ft_sleep(t_philo *philo, time_t time);
void			set_philo_state(t_philo *philo, t_state state);
void			destroy_philos(t_philo	*philo);
void			eating(t_philo *philo);
void			sleeping(t_philo	*philo);
void			thinking(t_philo	*philo);
time_t			get_last_meal_time(t_philo *philo);
time_t			get_time(void);
time_t			get_thinking_time(t_table *table);
t_philo			*init_philo(char **argv);
enum e_state	get_philo_state(t_philo	*philo);

#endif

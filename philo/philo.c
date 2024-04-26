/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:03:17 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/26 09:06:18 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (write(2, "invalid arguments\n", 18), 1);
	if (is_valid_input(argv) == 0)
		return (write(2, "invalid arguments\n", 18), 1);
	philo = init_philo(argv);
	if (philo == NULL)
		return (printf("error_malloc"), 1);
	if (dining_philo(philo) == 0)
		return (free_ptr((void **)&philo->table->forks), free_philo(philo),
			printf("error\n"), 1);
	destroy_philos(philo);
	return (0);
}

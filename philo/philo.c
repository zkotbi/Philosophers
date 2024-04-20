/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:30:57 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/18 12:34:24 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philo *philo;

	if (argc < 5 || argc > 6)
		return (write(2, "invalid arguments\n", 18), 1);
	if (is_valid_input(argv) == 0)
		return (write(2, "invalid arguments\n", 18), 1);
	philo = init_philo(argv);
	if (philo == NULL)
		return (printf("error_malloc"), 1);
	if (dining_philo(philo) == 0)
		return (printf("error\n"), 1);
	return (0);
}

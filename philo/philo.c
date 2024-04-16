/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:17:22 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/16 22:01:30 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (write(2, "invalid arguments\n", 18));
	if (is_valid_input(argv) == 0)
		return (write(2, "invalid arguments\n", 18));
	init_philo(argv);
}

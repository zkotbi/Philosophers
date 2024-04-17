/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:30:57 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/17 11:05:22 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (write(2, "invalid arguments\n", 18), 1);
	if (argv != NULL)
		printf("test\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <hibenouk@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:11:53 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/18 12:18:16 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *free_ptr(void	**ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

void *free_philo(t_philo *philo)
{
	free_ptr((void **)&(philo->table));
	free_ptr((void **)&philo);
	return (NULL);
}

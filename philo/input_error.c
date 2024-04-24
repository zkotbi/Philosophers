/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkotbi <zkotbi@1337.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:03:34 by zkotbi            #+#    #+#             */
/*   Updated: 2024/04/24 00:03:36 by zkotbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	empty_arg(char	**argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][j] == 0)
			return (0);
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	is_numeric(char	**argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (argv[i][j] == 0)
				break ;
			if ((argv[i][j] == '+')
			&& (argv[i][j + 1] >= 48 && argv[i][j + 1] <= 57)
			&& (argv[i][j - 1] < 48 || argv[i][j - 1] > 57))
				j++;
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 0)
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_input(char **argv)
{
	if (empty_arg(argv) == 0)
		return (0);
	if (is_numeric(argv) == 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:36:50 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:51 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	gettime(char t)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Error getting time");
	if (t == 'S')
		return (tv.tv_sec + (tv.tv_usec / 1000000));
	else if (t == 'M')
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	else if (t == 'U')
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	else
		error_exit("Error getting time");
	return (0);
}

int	precise_usleep(long usec, t_philo *philo)
{
	long	start;

	start = gettime('U');
	while ((gettime('U') - start) < usec)
	{
		usleep(100);
		if (philo_death(philo))
			return (0);
	}
	return (1);
}

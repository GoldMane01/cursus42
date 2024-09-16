/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:56:01 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/16 16:56:02 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	start_one_philo(t_table *table)
{
	if (pthread_create(&table->philos[0].thread_id, NULL, one_philo,
			&table->philos[0]) != 0)
		return (error_exit("Error creating thread"));
	return (1);
}

int	start_all_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_philos)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				dinner_sim, &table->philos[i]) != 0)
			return (error_exit("Error creating thread"));
	}
	return (1);
}

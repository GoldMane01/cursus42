/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:41:33 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 15:41:34 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(char	*error)
{
	printf("%s", error);
	exit(EXIT_FAILURE);
}

void	start_sim(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->nbr_philos == 1)
		start_one_philo(table);
	else
		start_all_philos(table);
	if (pthread_create(&table->death, NULL, check_death, table) != 0)
		error_exit("Error creating thread");
	table->start_simulation = gettime('M');
	set_bool(&table->table_mutex, &table->threads_ready, true);
	i = -1;
	while (++i < table->nbr_philos)
	{
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
			error_exit("Error joining thread");
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		error_exit("Bad input\n");
	}
	else
	{
		get_data(&table, argv);
		init_data(&table);
		start_sim(&table);
		//clean(&table);
	}
}

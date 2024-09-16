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

int	error_exit(char	*error)
{
	printf("%s", error);
	return (0);
}

int	start_sim(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return (1);
	else if (table->nbr_philos == 1)
		start_one_philo(table);
	else
		start_all_philos(table);
	if (pthread_create(&table->death, NULL, check_death, table) != 0)
		return (error_exit("Error creating thread"));
	table->start_simulation = gettime('M');
	set_bool(&table->table_mutex, &table->threads_ready, true);
	i = -1;
	while (++i < table->nbr_philos)
	{
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
			return (error_exit("Error joining thread"));
	}
	return (1);
}

void	clean(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->table_mutex);
	pthread_mutex_destroy(&table->write_mutex);
	i = -1;
	if (table->forks)
	{
		while (++i < table->nbr_philos)
			pthread_mutex_destroy(&table->forks[i].fork);
		free(table->forks);
	}
	i = -1;
	if (table->philos)
	{
		while (++i < table->nbr_philos)
			pthread_mutex_destroy(&table->philos[i].philo_mutex);
		free(table->philos);
	}
	free(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
	{
		error_exit("Bad input\n");
		return (1);
	}
	else
	{
		table = malloc(sizeof(t_table));
		if (!table)
			return (1);
		if (!get_data(table, argv))
			return (1);
		if (!init_data(table))
			return (1);
		if (!start_sim(table))
			return (1);
		free(table->forks);
		free(table->philos);
		free(table);
	}
	return (0);
}

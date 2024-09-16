/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:36:12 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:13 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_data(t_table *table)
{
	if (table->nbr_philos <= 0
		|| table->time_to_die <= 0
		|| table->time_to_eat <= 0
		|| table->time_to_sleep <= 0)
		return (error_exit("Invalid values\n"));
	return (1);
}

int	get_data(t_table *table, char **argv)
{
	table->nbr_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
	if (!check_data(table))
		return (0);
	return (1);
}

int	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nbr_philos)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meal_total = 0;
		philo->table = table;
		if (!mtx_switch(&philo->philo_mutex, 'I'))
			return (0);
		assign_forks(philo, table->forks, i);
	}
	return (1);
}

int	init_data(t_table *table)
{
	int	i;

	i = -1;
	table->end_simlation = false;
	table->nbr_threads_running = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philos);
	if (table->philos == NULL)
		return (error_exit("Malloc error\n"));
	if (!mtx_switch(&table->table_mutex, 'I'))
		return (0);
	if (!mtx_switch(&table->write_mutex, 'I'))
		return (0);
	table->forks = malloc(sizeof(t_fork) * table->nbr_philos);
	if (table->forks == NULL)
		return (error_exit("Malloc error\n"));
	while (++i < table->nbr_philos)
	{
		if (!mtx_switch(&table->forks[i].fork, 'I'))
			return (0);
		table->forks[i].fork_id = i;
	}
	if (!init_philo(table))
		return (0);
	return (1);
}

void	assign_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	nphilo;

	nphilo = philo->table->nbr_philos;
	philo->first_fork = &forks[(pos + 1) % nphilo];
	philo->second_fork = &forks[pos];
	if ((philo->id % 2) == 0)
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % nphilo];
	}
}

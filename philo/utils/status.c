/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:36:34 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:35 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	sim_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}

void	wait_for_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->threads_ready))
		;
}

void	write_status(char c, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime('M') - philo->table->start_simulation;
	if (philo->full)
		return ;
	mtx_switch(&philo->table->write_mutex, 'L');
	if (c == 'F' && !sim_finished(philo->table))
		printf("%ld\t%d has taken a fork\n", elapsed, philo->id);
	else if (c == 'E' && !sim_finished(philo->table))
		printf("%ld\t%d is eating\n", elapsed, philo->id);
	else if (c == 'S' && !sim_finished(philo->table))
		printf("%ld\t%d is sleeping\n", elapsed, philo->id);
	else if (c == 'T' && !sim_finished(philo->table))
		printf("%ld\t%d is thinking\n", elapsed, philo->id);
	else if (c == 'D')
		printf("%ld\t%d died\n", elapsed, philo->id);
	mtx_switch(&philo->table->write_mutex, 'U');
}

void	eat(t_philo *philo)
{
	mtx_switch(&philo->first_fork->fork, 'L');
	write_status('F', philo);
	if (mtx_switch(&philo->second_fork->fork, 'L') == 0)
		mtx_switch(&philo->first_fork->fork, 'U');
	write_status('F', philo);
	write_status('E', philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime('M'));
	if (precise_usleep(philo->table->time_to_eat, philo) == 0)
	{
		mtx_switch(&philo->first_fork->fork, 'U');
		mtx_switch(&philo->second_fork->fork, 'U');
	}
	philo->meal_total++;
	if (philo->table->nbr_limit_meals > 0
		&& philo->meal_total == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	mtx_switch(&philo->first_fork->fork, 'U');
	mtx_switch(&philo->second_fork->fork, 'U');
}

void	thinking(t_philo *philo)
{
	write_status('T', philo);
	if (philo->table->nbr_philos % 2 != 0)
	{
		precise_usleep(philo->table->time_to_eat, philo);
	}
}

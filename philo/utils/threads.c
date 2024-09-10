#include "../philo.h"

bool	all_threads_running(pthread_mutex_t *mutex, long *threads, long nbr)
{
	bool	ret;

	ret = false;
	mtx_switch(mutex, 'L');
	if (*threads == nbr)
		ret = true;
	mtx_switch(mutex, 'U');
	return (ret);
}

bool	philo_death(t_philo *philo)
{
	long	elapsed;
	long	death_time;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = gettime('M') - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	death_time = philo->table->time_to_die / 1000;
	if (elapsed > death_time)
		return (true);
	return (false);
}

void	*check_death(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex,
			&table->nbr_threads_running, table->nbr_philos))
		;
	while (!sim_finished(table))
	{
		i = -1;
		while (++i < table->nbr_philos && !sim_finished(table))
		{
			if (philo_death(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end_simlation, true);
				write_status('D', table->philos + i);
			}
		}
	}
	return (NULL);
}

void	*one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_for_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime('M'));
	increase_long(&philo->table->table_mutex,
		&philo->table->nbr_threads_running);
	write_status('F', philo);
	while (!sim_finished(philo->table))
		usleep(200);
	return (NULL);
}

void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_for_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime('M'));
	increase_long(&philo->table->table_mutex,
		&philo->table->nbr_threads_running);
	while (!sim_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status('S', philo);
		precise_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

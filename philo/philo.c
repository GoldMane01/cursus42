#include "philo.h"

#include <errno.h>

void	error_exit(char	*error)
{
	printf("%s", error);
	exit(EXIT_FAILURE);
}

void	check_data(t_table *table)
{
	if (table->nbr_philos <= 0 ||
		table->time_to_die <= 0 ||
		table->time_to_eat <= 0 ||
		table->time_to_sleep <= 0)
		error_exit("Invalid values\n");
}

void	get_data(t_table *table, char **argv)
{
	table->nbr_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
	check_data(table);
}

void	mutex_error_handle(int mtx_return)
{
	if (mtx_return != 0)
		error_exit("There has been an error using mutex\n");
}

void	mtx_switch(pthread_mutex_t *mutex, char c)
{
	if (c == 'L')
		mutex_error_handle(pthread_mutex_lock(mutex));
	else if (c == 'U')
		mutex_error_handle(pthread_mutex_unlock(mutex));
	else if (c == 'I')
		mutex_error_handle(pthread_mutex_init(mutex, NULL));
	else if (c == 'D')
		mutex_error_handle(pthread_mutex_destroy(mutex));
	else
		error_exit("Mutex switch error\n");
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

void	init_philo(t_table *table)
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
		mtx_switch(&philo->philo_mutex, 'I');
		assign_forks(philo, table->forks, i);
	}
}

void	init_data(t_table *table)
{
	int	i;

	i = -1;
	table->end_simlation = false;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philos);
	if (table->philos == NULL)
		error_exit("Malloc error\n");
	mtx_switch(&table->table_mutex, 'I');
	table->forks = malloc(sizeof(t_fork) * table->nbr_philos);
	if (table->forks == NULL)
		error_exit("Malloc error\n");
	while (++i < table->nbr_philos)
	{
		mtx_switch(&table->forks[i].fork, 'I');
		table->forks[i].fork_id = i;
	}
	init_philo(table);
}

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	mtx_switch(mutex, 'L');
	*dest = value;
	mtx_switch(mutex, 'U');
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	ret;

	mtx_switch(mutex, 'L');
	ret = *value;
	mtx_switch(mutex, 'U');
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	mtx_switch(mutex, 'L');
	*dest = value;
	mtx_switch(mutex, 'U');
}

bool	get_long(pthread_mutex_t *mutex, long *value)
{
	long	ret;

	mtx_switch(mutex, 'L');
	ret = *value;
	mtx_switch(mutex, 'U');
	return (ret);
}

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

bool	sim_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simlation));
}

void	wait_for_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->threads_ready))
		;
}

void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = gettime('U');
	while (gettime('U') - start < usec)
	{
		if (sim_finished(table))
			break ;
		elapsed = gettime('U') - start;
		remaining = usec - elapsed;
		if (remaining > 1000)
			usleep(usec / 2);
		else
		{
			while (gettime('U') - start < usec)
				;
		}
	}
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
	mtx_switch(&philo->second_fork->fork, 'L');
	write_status('F', philo);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime('M'));
	philo->meal_total++;
	write_status('E', philo);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meal_total == philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	mtx_switch(&philo->first_fork->fork, 'U');
	mtx_switch(&philo->second_fork->fork, 'U');
}

//TODOODODODODODODD
void	thinking(t_philo *philo)
{
	write_status('T', philo);
}

void	*dinner_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("COÑO");
	wait_for_threads(philo->table);
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

void	start_sim(t_table *table)
{
	int	i;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (table->nbr_limit_meals == 1)
		;
	else
	{
		while (++i)
		{
			if (pthread_create(&table->philos[i].thread_id, NULL, &dinner_sim, &table->philos[i]) != 0)
				error_exit("Error creating thread");
		}
	}
	table->start_simulation = gettime('M');
	set_bool(&table->table_mutex, &table->threads_ready, true);
	i = -1;
	while(++i < table->nbr_philos)
	{
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
			error_exit("Error joining thread"); //Error returns ESRCH, No thread with the ID found
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
#include "philo.h"

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
		//start_sim(&table);
		//clean(&table);
	}
}
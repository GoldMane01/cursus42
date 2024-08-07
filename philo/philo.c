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

void	init_data(t_table *table)
{
	table->end_simlation = false;
	table->philos = malloc(sizeof(t_philo) * table->nbr_philos);
	if (table->philos == NULL)
		error_exit("Malloc error\n");
	table->forks = malloc(sizeof(t_fork) * table->nbr_philos);
	if (table->forks == NULL)
		error_exit("Malloc error\n");
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
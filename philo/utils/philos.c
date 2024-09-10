#include "../philo.h"

void	start_one_philo(t_table *table)
{
	if (pthread_create(&table->philos[0].thread_id, NULL, one_philo,
			&table->philos[0]) != 0)
		error_exit("Error creating thread");
}

void	start_all_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_philos)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				dinner_sim, &table->philos[i]) != 0)
			error_exit("Error creating thread");
	}
}

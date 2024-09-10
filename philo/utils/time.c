#include "../philo.h"

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

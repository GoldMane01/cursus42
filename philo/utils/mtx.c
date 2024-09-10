#include "../philo.h"

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
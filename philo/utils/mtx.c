/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:36:19 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:20 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mutex_error_handle(int mtx_return)
{
	if (mtx_return != 0)
		return (error_exit("There has been an error using mutex\n"));
	return (1);
}

int	mtx_switch(pthread_mutex_t *mutex, char c)
{
	if (c == 'L')
		return (mutex_error_handle(pthread_mutex_lock(mutex)));
	else if (c == 'U')
		return (mutex_error_handle(pthread_mutex_unlock(mutex)));
	else if (c == 'I')
		return (mutex_error_handle(pthread_mutex_init(mutex, NULL)));
	else if (c == 'D')
		return (mutex_error_handle(pthread_mutex_destroy(mutex)));
	else
		return (error_exit("Mutex switch error\n"));
}

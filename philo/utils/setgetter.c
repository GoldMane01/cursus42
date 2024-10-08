/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setgetter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:36:27 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 16:36:28 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	ret;

	mtx_switch(mutex, 'L');
	ret = *value;
	mtx_switch(mutex, 'U');
	return (ret);
}

void	increase_long(pthread_mutex_t *mutex, long *val)
{
	mtx_switch(mutex, 'L');
	(*val)++;
	mtx_switch(mutex, 'U');
}

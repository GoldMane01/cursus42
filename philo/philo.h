/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:41:43 by dramos-n          #+#    #+#             */
/*   Updated: 2024/09/10 15:41:45 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>

typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef struct s_philo
{
	int				id;
	int				meal_total;
	bool			full;
	long			last_meal_time;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread_id;
	pthread_mutex_t	philo_mutex;
	t_table			*table;
}					t_philo;

typedef struct s_table
{
	long			nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			start_simulation;
	long			nbr_threads_running;
	bool			end_simlation;
	bool			threads_ready;
	pthread_mutex_t	table_mutex;
	pthread_mutex_t	write_mutex;
	pthread_t		death;
	t_fork			*forks;
	t_philo			*philos;
}				t_table;

int		error_exit(char	*error);
long	ft_atol(const char *str);
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
long	get_long(pthread_mutex_t *mutex, long *value);
void	increase_long(pthread_mutex_t *mutex, long *val);
int		mutex_error_handle(int mtx_return);
int		mtx_switch(pthread_mutex_t *mutex, char c);
int		check_data(t_table *table);
int		get_data(t_table *table, char **argv);
int		init_philo(t_table *table);
int		init_data(t_table *table);
void	assign_forks(t_philo *philo, t_fork *forks, int pos);
bool	all_threads_running(pthread_mutex_t *mutex, long *threads, long nbr);
bool	philo_death(t_philo *philo);
void	*check_death(void *data);
void	*one_philo(void *data);
void	*dinner_sim(void *data);
bool	sim_finished(t_table *table);
void	wait_for_threads(t_table *table);
void	write_status(char c, t_philo *philo);
void	eat(t_philo *philo);
void	thinking(t_philo *philo);
long	gettime(char t);
int		precise_usleep(long usec, t_philo *philo);
int		start_one_philo(t_table *table);
int		start_all_philos(t_table *table);

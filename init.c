/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:29 by arforouz          #+#    #+#             */
/*   Updated: 2024/09/13 19:35:04 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
	{
		fprintf(stderr, "Error: Failed to allocate memory for forks\n");
		return (1);
	}
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->check_death_mutex, NULL);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
	{
		printf("Error: Failed to allocate memory for philosophers\n");
		free(data->forks);
		return (1);
	}
	i = 0;
	while (i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = i;
		data->philos[i].r_fork = (i + 1) % data->philo_num;
		data->philos[i].dead_flag = 0;
		data->philos[i].times_eaten = 0;
		data->philos[i].last_eat = get_current_time();
		data->philos[i].start_time = get_current_time();
		pthread_mutex_init(&data->philos[i].eat_mutex, NULL);
		i++;
	}
	return (0);
}

int	init_data(t_data *data)
{
	if (init_mutexes(data) != 0)
		return (1);
	if (init_philos(data) != 0)
	{
		free(data->forks);
		return (1);
	}
	return (0);
}

int	init_threads(t_data *data)
{
	pthread_t	monitor_thread;
	int			i;

	// if (data->philo_num == 1)
	// {
	// 	handle_case_one(&data->philos[0]);
	// 	return (0);
	// }
	if (pthread_create(&monitor_thread, NULL, &death_monitor, (void *)data))
		return (printf("Failed to create monitor thread\n"), 1);
	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]))
			return (printf("Failed to create philos thread %d\n", i + 1), 1);
	}
	i = -1;
	if (pthread_join(monitor_thread, NULL))
		return (printf("Error: Failed to join monitor thread\n"), 1);
	while (++i < data->philo_num)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (printf("Failed to join philosthread %d\n", i + 1), 1);
	}
	return (0);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].eat_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->check_death_mutex);
	free(data->forks);
	free(data->philos);
	free(data);
}

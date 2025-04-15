/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:54:16 by arforouz          #+#    #+#             */
/*   Updated: 2024/09/13 19:06:05 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finished(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_death_mutex);
	if (philo->data->dead_flag != 0)
	{
		pthread_mutex_unlock(&philo->data->check_death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->check_death_mutex);
	return (0);
}

int	check_all_ate(t_data *data)
{
	int	i;
	int	all_ate;
	int	times_eaten;

	i = 0;
	all_ate = 0;
	if (data->num_times_to_eat == -1)
		return (0);
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&(data->philos[i].eat_mutex));
		times_eaten = data->philos[i].times_eaten;
		pthread_mutex_unlock(&(data->philos[i].eat_mutex));
		if (times_eaten >= data->num_times_to_eat)
			all_ate++;
		i++;
	}
	if (all_ate == data->philo_num)
	{
		pthread_mutex_lock(&(data->check_death_mutex));
		data->dead_flag = 1;
		pthread_mutex_unlock(&(data->check_death_mutex));
		return (1);
	}
	return (0);
}

int	check_die(t_data *data)
{
	int		i;
	long	last_eat;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&(data->philos[i].eat_mutex));
		last_eat = data->philos[i].last_eat;
		pthread_mutex_unlock(&(data->philos[i].eat_mutex));
		if (get_current_time() - last_eat > data->time_to_die)
		{
			print_action(&data->philos[i], DEAD);
			pthread_mutex_lock(&(data->check_death_mutex));
			data->dead_flag = 1;
			pthread_mutex_unlock(&(data->check_death_mutex));
			return (1);
		}
		i++;
	}
	return (0);
}

void	*death_monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_die(data) || check_all_ate(data))
		{
			break ;
		}
	}
	return (arg);
}

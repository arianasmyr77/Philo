/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:42:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 15:13:50 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_time(t_philo *philo)
{
	print_action(philo, THINK);
}

void	dinner(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->forks[philo->l_fork]);
	print_action(philo, TAKE_FORK);
	// if (data->philo_num == 1)
	// {
	// 	ft_usleep(data->time_to_die);
	// 	print_action(philo, DEAD);
	// 	return ;
	// }
	pthread_mutex_lock(&data->forks[philo->r_fork]);
	print_action(philo, TAKE_FORK);
	print_action(philo, EAT);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = get_current_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[philo->l_fork]);
	pthread_mutex_unlock(&data->forks[philo->r_fork]);
}

void	sleep_time(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_action(philo, SLEEP);
	ft_usleep(data->time_to_sleep);
}


void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		ft_usleep(30);
	}
	if (philo->data->philo_num == 1)
	{
		print_action(philo, TAKE_FORK);
		ft_usleep(philo->data->time_to_die);
		// print_action(philo, DEAD);
		return (0);
	}
	// if (philo->data->philo_num == 1)
	// {
	// 	handle_case_one(philo);
	// 	//free_all(data);
	// 	return (0);
	// }

	while (!check_finished(philo))
	{
		dinner(philo);
		sleep_time(philo);
		think_time(philo);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:45:27 by arforouz          #+#    #+#             */
/*   Updated: 2024/09/13 18:56:17 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int	is_negative;
	int	ret;

	ret = 0;
	is_negative = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_negative = -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		ret = (ret * 10) + (*str - '0');
		str++;
	}
	return (ret * is_negative);
}

int	ft_usleep(size_t millisec)
{
	size_t	s_time;

	s_time = get_current_time();
	while ((get_current_time() - s_time) < millisec)
		usleep(500);
	return (0);
}

void	print_action(t_philo *philo, const char *action)
{
	t_data	*data;
	long	time;

	data = philo->data;
	if (check_all_ate(data))
		return ;
	pthread_mutex_lock(&data->message);
	time = get_current_time() - data->start_time;
	if (data->dead_flag != 1)
	{
		printf("%ld ms %d %s\n", time, philo->id, action);
	}
    pthread_mutex_unlock(&data->message);
}

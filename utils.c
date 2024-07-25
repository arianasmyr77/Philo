/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:45:27 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 15:39:13 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long     get_current_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
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

void ft_usleep(long time_in_ms)
{
    long start_time = get_current_time();
    long end_time = start_time + time_in_ms;

    while (get_current_time() < end_time)
        usleep(100); // Sleep for a short duration to prevent busy-waiting
}

void print_action(t_philo *philo, const char *action)
{
    t_data *data = philo->data;
    time_t time;
    
    time = get_current_time() - data->start_time;
    pthread_mutex_lock(&data->message);
    printf("[%ld ms] Philosopher %d %s\n", time, philo->id, action);
    pthread_mutex_unlock(&data->message);
}

//los dos funcionan pero si en vez de time_t usas long no funciona 
// void print_action(t_philo *philo, const char *action)
// {
//     t_data *data = philo->data;
//     long time = get_current_time() - data->start_time;
//     pthread_mutex_lock(&data->message);
//     printf("[%ld ms] Philosopher %d %s\n", time, philo->id, action);
//     pthread_mutex_unlock(&data->message);
// }
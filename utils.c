/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:45:27 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/26 21:27:21 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long     get_current_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void ft_usleep(long time_in_ms)
{
    long start_time = get_current_time();
    long end_time = start_time + time_in_ms;

    while (get_current_time() < end_time)
        usleep(100); // Sleep for a short duration to prevent busy-waiting
}

void print_action(t_philo *philo, const char *action) {
    t_data *data = philo->data;
    long time 
    
    time = get_current_time() - data->start_time;
    pthread_mutex_lock(&data->message);
    printf("[%ld ms] Philosopher %d %s\n", current_time, philo->id, action);
    pthread_mutex_unlock(&data->message);
}


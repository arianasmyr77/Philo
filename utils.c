/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:45:27 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/25 11:55:52 by arforouz         ###   ########.fr       */
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


void print_action(char *str, t_philo *philo)
{
    long time;

    time = get_current_time() - philo->data->start_time;
}
int main() {
    // Get and print the current time in milliseconds
    long long current_time_ms = get_current_time();
    printf("Current time in milliseconds since the Epoch: %lld\n", current_time_ms);
    return 0;
}
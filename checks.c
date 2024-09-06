/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:54:16 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/26 22:32:35 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int all_philos_ate_enough(t_data *data)
{
    int i = 0;
    while (i < data->philo_num)
    {
        if (data->philos[i].eaten_times < data->num_times_to_eat)
            return 0;
        i++;
    }
    return 1;
}

int is_any_philo_dead(t_data *data)
{
    int i = 0;
    while (i < data->philo_num)
    {
        if (data->philos[i].dead_flag)
        {
            return 1;
        }  
        i++;
    }
    return 0;
}

int check_death(t_data *data)
{
    int i;
    long current_time = get_current_time();

    pthread_mutex_lock(&data->check_death_mutex);
    i = 0;
    while (i < data->philo_num)
    {
        if ((current_time - data->philos[i].last_eat) > data->time_to_die)
        {
            data->dead_flag = 1;
            print_action(&data->philos[i], DEAD);
            pthread_mutex_unlock(&data->check_death_mutex);
            return 1;
        }
        i++;
    }
    pthread_mutex_unlock(&data->check_death_mutex);
    return 0;
} 

// int check_die(t_data *data, t_philo *philo)
// {
//     int time;

//     // Check if any philosopher has died (global state check)
//     pthread_mutex_lock(&(data->check_death_mutex));
//     if (data->dead_flag) {
//         pthread_mutex_unlock(&(data->check_death_mutex));
//         return 1;
//     }
//     pthread_mutex_unlock(&(data->check_death_mutex));

//     // Check if this philosopher has died (individual state check)
//     time = get_current_time();
//     if (time - (philo->last_eat) > data->time_to_die) {
//         pthread_mutex_lock(&(data->check_death_mutex));
//         data->dead_flag = 1;  // Set the global dead flag
//         pthread_mutex_unlock(&(data->check_death_mutex));
//         print_action(philo, DEAD);
//         return 1;
//     }

//     return 0;
// }
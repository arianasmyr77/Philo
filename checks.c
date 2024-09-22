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
#include "philo.h"
//CFLAGS	= -Wall -Werror -Wextra -fsanitize=leaks

 int check_die(t_data *data, t_philo *philo)
{
    long time;

    pthread_mutex_lock(&(data->check_death_mutex));
    if (data->dead_flag)
    {
        pthread_mutex_unlock(&(data->check_death_mutex));
        return (1);
    }
    pthread_mutex_unlock(&(data->check_death_mutex));
    time = get_current_time();
    if (time - philo->last_eat > data->time_to_die)
    {
        print_action(philo, DEAD); 
        pthread_mutex_lock(&(data->check_death_mutex));
        data->dead_flag = 1; 
        pthread_mutex_unlock(&(data->check_death_mutex));
        return (1);
    }
    return (0);
} 

int check_all_ate(t_data *data)
{
    int i;

    if (data->num_times_to_eat == -1)
        return (0);
    i = 0;
    while (i < data->philo_num)
    {
        if (data->philos[i].times_eaten < data->num_times_to_eat)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

void *death_monitor(void *arg)
{
    t_data *data = (t_data *)arg;
    while (1)
    {
        int i = 0;
        while (i < data->philo_num)
        {
            if (check_die(data, &data->philos[i]))
                return (0);
            i++;
        }
        usleep(1000);
    }
}

// int check_die(t_data *data)
// {
//     int i;
//     long current_time;

//     for (i = 0; i < data->philo_num; i++) {
//         current_time = get_current_time();
//         pthread_mutex_lock(&(data->check_death_mutex));
//         if (current_time - data->philos[i].last_eat > data->time_to_die) {
//             data->dead_flag = 1;
//             pthread_mutex_unlock(&(data->check_death_mutex));
//             print_action(&data->philos[i], "died");
//             return 1;
//         }
//         pthread_mutex_unlock(&(data->check_death_mutex));
//     }
//     return 0;
// }

// int check_all_ate(t_data *data) {
//     int i;
//     int ate_enough_count = 0;

//     for (i = 0; i < data->philo_num; i++) {
//         pthread_mutex_lock(&(data->philo_can_eat));
//         if (data->philos[i].times_eaten >= data->num_times_to_eat) {
//             ate_enough_count++;
//         }
//         pthread_mutex_unlock(&(data->philo_can_eat));
//     }
//     if (ate_enough_count == data->philo_num) {
//         data->all_ate_enough = 1;
//         return 1;  // All philosophers ate enough
//     }
//     return 0;  // Not all have eaten enough yet
// }

// void *monitor_routine(void *arg) {
//     t_data *data = (t_data *)arg;

//     while (1) {
//         if (check_die(data) || check_all_ate(data)) {
//             break;
//         }
//         usleep(1000);
//     }
//     return NULL;
// }

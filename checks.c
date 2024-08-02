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
// uncomment this later if new changes didn't wokr
// thee code beloww is not compiling good don't use 
// int all_philos_ate_enough(t_data *data)
// {
//     int i;
//     int all_ate;

//     i = 0;
//     all_ate = 1;
//     pthread_mutex_lock(&data->check_death_mutex);
//     while (i < data->philo_num)
//     {
//         if (data->philos[i].eaten_times < data->num_times_to_eat)
//         {
//             all_ate = 0;
//             break;
//         }
//         i++;
//     }
//     pthread_mutex_unlock(&data->check_death_mutex);
//     return (all_ate);
// }

// int is_any_philo_dead(t_data *data)
// {
//     int i;
//     int dead;

//     pthread_mutex_lock(&data->check_death_mutex);
//     while (i < data->philo_num)
//     {
//         if (data->philos[i].dead_flag)
//         {
//             dead = 1;
//             break ;
//         }
//         i++;
//     }
//     pthread_mutex_unlock(&data->check_death_mutex);

//     return (dead);
// }

/*
void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data;

    while (is_any_philo_dead(data)) 
    {
        if (all_philos_ate_enough(data)) 
        {
            break ;
        }
        //pthread_mutex_lock(&data->check_death_mutex);
        dinner(philo);
        sleep_time(philo);
        think_time(philo);
        pthread_mutex_lock(&data->check_death_mutex);
        philo->eaten_times++;
        data->all_ate_enough = all_philos_ate_enough(data);
        pthread_mutex_unlock(&data->check_death_mutex);
    }
    return NULL;
}*/

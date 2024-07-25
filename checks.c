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
            return 1;
        i++;
    }
    return 0;
}
//uncomment this later if new changes didn't wokr
//thee code beloww is not compiling good don't use 
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
// int check_philo_death(t_data *data)
// {
//     int any_dead;

//     pthread_mutex_lock(&(data->any_dead_mutex));
//     any_dead = data->any_dead;
//     pthread_mutex_unlock(&(data->any_dead_mutex));
//     return (any_dead);
// }

// int check_die(t_data *data, t_philo *philo, int check_any)
// {
//     int time;

//     if (check_any)
//     {
//         if (check_philo_death(data))
//             return (1);
//     }

//     time = get_time(data);
//     if (time - philo->last_eat > data->time_to_die)
//     {
//         print_philo_msg(data, philo->id, DEAD);
//         return (1);
//     }
//     return (0);
// }

// int check_philo_last_meal()
// void    any_dead_philosopher()
// {
//     int dead = 0;
//     pthread_mutex_lock(data->death_mutex)
// }
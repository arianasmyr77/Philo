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

int check_die(t_data *data, t_philo *philo)
{
    int time;

    pthread_mutex_lock(&(data->check_death_mutex));
    if (data->dead_flag) {
        pthread_mutex_unlock(&(data->check_death_mutex));
        return 1;
    }
    pthread_mutex_unlock(&(data->check_death_mutex));
    time = get_current_time();
    if (time - (philo->last_eat) > data->time_to_die) {
        pthread_mutex_lock(&(data->check_death_mutex));
        data->dead_flag = 1; 
        pthread_mutex_unlock(&(data->check_death_mutex));
        print_action(philo, DEAD);
        return 1;
    }

    return 0;
}

int check_all_ate(t_data *data) {
    int i;

    if (data->num_times_to_eat == -1)
        return 0;

    i = 0;
    while (i < data->philo_num) {
        if (data->philos[i].times_eaten < data->num_times_to_eat)
            return 0;
        i++;
    }
    return 1;
}

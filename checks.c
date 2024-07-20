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

void    check_arguments(t)
{
    if (data->philo_num <= 0)
        return (1);
    else if (data->time_to_eat <= 0)
        return (1);
    else if (data->time_to_sleep <= 0)
        return (1);
    else if (data->time_to_think <= 0)
        return (1) ;
}

int check_philo_death(t_data *data)
{
    int any_dead;

    pthread_mutex_lock(&(data->any_dead_mutex));
    any_dead = data->any_dead;
    pthread_mutex_unlock(&(data->any_dead_mutex));
    return (any_dead);
}


int check_die(t_data *data, t_philo *philo, int check_any)
{
    int time;

    if (check_any)
    {
        if (check_philo_death(data))
            return (1);
    }

    time = get_time(data);
    if (time - philo->last_eat > data->time_to_die)
    {
        print_philo_msg(data, philo->id, DEAD);
        return (1);
    }
    return (0);
}
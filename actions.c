/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:42:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 15:13:50 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
//pthread_mutex_t forks[NUM_PHILOSOPHERS]; // Mutexes for each fork
drop_forks()
{
     pthread_mutex_unlock(&forks[philo->r_fork]);
    pthread_mutex_unlock(&forks[philo->l_fork]);
    //print__action(philo sleeping)
}*/



void spageti_table_for_philos(t_philo *philo)
{
    t_data  *data;

    data = philo->data;
    pthread_mutex_lock(&data->forks[philo->l_fork]);
    print_action(philo, Take_FORK);
    pthread_mutex_lock(&data->forks[philo->r_fork]);
    print_action(philo, Take_FORK);
    print_action(philo, EAT);
    usleep(data->time_to_eat * 1000);
    pthread_mutex_unlock(&data->forks[philo->l_fork]);
    pthread_mutex_unlock(&data->forks[philo->r_fork]);
    print_action(philo, SLEEP);
    usleep(data->time_to_sleep * 1000);
    print_action(philo, THINK);
    usleep(data->time_to_think * 1000);

}

// void *philosopher(void *arg) {
//     t_philo *philo = (t_philo *)arg;

//     while (!philo->dead_flag) {
//        spageti_table_for_philos(&philo);
//     }

//     print_action(philo->philo_id, DIED);

//     return NULL;
// }

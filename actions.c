/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:42:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/24 13:32:43 by arforouz         ###   ########.fr       */
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

void time_to_eat(t_philo *philo)
{
    long time;

    pthread_mutex_lock(&philo->l_fork);
    print_action("philo has taken a fork");
    pthread_mutex_lock(&philo->r_fork);
    print_action("philo has taken a fork");
    time = get_current_time() - philo->start_time;
    print_action(philo->philo_id, EAT);
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&philo->r_fork);
    time = get_current_time() - philo->start_time;
    print_action("philo is sleeping");
    usleep(200);
    time  = get_current_time() - philo->start_time;
    print_action("philo is thinking");
}

// void *philosopher(void *arg) {
//     t_philo *philo = (t_philo *)arg;

//     while (!philo->dead_flag) {
//         print_action(philo->philo_id, THINK);
//         usleep(1000);

//         print_action(philo->philo_id, FORK);
//         usleep(1000);

//         print_action(philo->philo_id, EAT);
//         usleep(2000);

//         print_action(philo->philo_id, SLEEP);
//         usleep(1000);
//     }

//     print_action(philo->philo_id, DIED);

//     return NULL;
// }

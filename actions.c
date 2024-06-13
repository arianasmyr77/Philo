/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:42:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/13 18:30:08 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

get_forks()
{
    pthread_mutex_lock(&philo->l_fork);
    pthread_mutex_lock(&philo->r_fork);
    //print_action(philo[i] hast taken a fork);
    // or print_action(EAT)
}
 
drop_forks()
{
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&philo->r_fork);
    //print__action(philo sleeping)
}

void time_to_eat(t_philo *philo)
{
    long time;

    pthread_mutex_lock(&philo->l_fork);
    print_action("philo has taken a fork");
    pthread_mutex_lock(&philo->r_fork);
    print_action("philo has taken a fork");
    time = get_current_time() - philo->start_time;
    print_action(philo is eating);
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&philo->r_fork);
    time = get_current_time() - philo->start_time;
    print_action("philo is sleeping");
    usleep(200);
    time  = get_current_time() - philo->start_time;
    print_action("philo is thinking");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:42:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/12 21:52:01 by arforouz         ###   ########.fr       */
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

int time_to_eat(t_data *data, t_philo *philo)
{
    pthread_mutex_lock(&philo->l_fork);
    pthread_mutex_lock(&philo->r_fork);
    print_action(philo is eating);
    pthread_mutex_unlock(&philo->l_fork);
    pthread_mutex_unlock(&philo->r_fork);
    //print__action(philo sleeping)

    
}

 


int time_to_think(t_)

time_to_sleep()

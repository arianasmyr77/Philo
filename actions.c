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

void    think_time(t_philo *philo)
{
    print_action(philo, THINK);
}

void dinner(t_philo *philo)
{
    t_data  *data;

    data = philo->data;
   // pthread_mutex_lock(&data->philo_can_eat);
    pthread_mutex_lock(&data->forks[philo->r_fork]);
    print_action(philo, Take_FORK);
    pthread_mutex_lock(&data->forks[philo->l_fork]);
    print_action(philo, Take_FORK);
    //pthread_mutex_lock(&data->philo_can_eat);
    print_action(philo, EAT);
    pthread_mutex_lock(&data->philo_can_eat);
    philo->last_eat = get_current_time();
    philo->eaten_times++;
    pthread_mutex_unlock(&data->philo_can_eat);
    ft_usleep(data->time_to_eat);
    pthread_mutex_unlock(&data->forks[philo->l_fork]);
    pthread_mutex_unlock(&data->forks[philo->r_fork]);
    //pthread_mutex_unlock(&data->philo_can_eat);
}

void  sleep_time(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    print_action(philo, SLEEP);
    ft_usleep(data->time_to_sleep);
}


void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data;

    while (!(check_die(data, philo))) {
        if(data->philo_num % 2 == 0)
        {
            ft_usleep(1);
        }
        dinner(philo);
        sleep_time(philo);
        think_time(philo);
    }
    return NULL;
}

// void *routine(void *arg)
// {
//     t_philo *philo = (t_philo *)arg;
//     t_data *data = philo->data;

//     while ((!is_any_philo_dead(data))) 
//     {
//             if (all_philos_ate_enough(data)) 
//             {
//                 break ;
//             }
//         dinner(philo);
//         sleep_time(philo);
//         think_time(philo);
//       //  pthread_mutex_lock(&data->check_death_mutex);
//        // philo->eaten_times++;
//         //data->all_ate_enough = all_philos_ate_enough(data);
//        // pthread_mutex_unlock(&data->check_death_mutex);
//     }
//     return NULL;
// }



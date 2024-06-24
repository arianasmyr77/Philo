/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:29 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/24 13:22:04 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *init_philos(void *argv)
{
    int r_fork = philo_id;
    
}

void    creat_philo(t_data *philo)
{
    pthread_t threads[NUM_PHILOSOPHERS];
    t_philo philois[NUM_PHILOSOPHERS];
    int i;

    i = 0;
    while (i < t_data->philo_num)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
    while (i < t_data->philo_num)
    {
        philos[i].pos = i;
        philos[i].id = i + 1;
        philos[i].l_fork = i;
        philos[i].r_for = (i + 1) % NUM_PHILOSOPHERS;
        philos[i].dead_flag = 0;
    }
    if (pthread_create(&threads[i], NULL, philosopher, &philoophers[i] != 0))
    {
       perror ("pthread_creat");
        return 1;
    }
      for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return 1;
        }
    }
    
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
void    init_data(t_data *philo)
{
    t_philo *philos;

    t_philo->philo_num = ft_atoi(argv[1]);
    t_philo->time_to_die  = ft_atoi(argv[2]);
    t_philo->time_to_eat = ft_atoi(argv[3]);
    t_philo->time_to_sleep = ft_atoi(argv[4]);
}


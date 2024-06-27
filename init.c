/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:29 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 15:17:53 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philos(t_data *data)
{
    int i;

    data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_num);

    //initializing mutexes for fokrs
    i = 0;
    while (i < data->philo_num)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    i = 0;
    while (i < data->philo_num)
    {
        data->philos[i].data = data;
        data->philos[i].pos = i;
        data->philos[i].id = i + 1;
        data->philos[i].l_fork = i;
        data->philos[i].r_fork = (i + 1) % data->philo_num;
        data->philos[i].dead_flag = 0;
    }

    pthread_mutex_init(&data->message, NULL);
    pthread_mutex_init(&data->check_final_eating, NULL);
    // if (pthread_create(&threads[i], NULL, philosopher, &philoophers[i] != 0))
    // {
    //    perror ("pthread_creat");
    //     return 1;
    // }
    //   for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    //     if (pthread_join(threads[i], NULL) != 0) {
    //         perror("pthread_join");
    //         return 1;
    //     }
    // }
    
    // for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    //     pthread_mutex_destroy(&forks[i]);
    // }

    // return 0;
}

void    free_data(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_num)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }

    pthread_mutex_destroy(&data->message);
    pthread_mutex_destroy(&data->check_final_eating);

    free(data->forks);
    free(data->philos);
    free(data);
}
 
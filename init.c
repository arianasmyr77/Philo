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

void    init_data(t_data *data)
{
    int i;

    data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_num);
    pthread_mutex_init(&data->message, NULL);
    pthread_mutex_init(&data->check_death_mutex, NULL);
    pthread_mutex_init(&data->philo_can_eat, NULL);
    pthread_mutex_init(&data->check_death_mutex, NULL);
    i = 0;
    while (i < data->philo_num)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
    i = 0;
    while (i < data->philo_num)
    {
        data->philos[i].data = data;
        data->philos[i].id = i + 1;
        data->philos[i].l_fork = i;
        data->philos[i].r_fork = (i + 1) % data->philo_num;
        data->philos[i].dead_flag = 0;
        data->philos[i].times_eaten = 0;
        data->philos[i].last_eat = get_current_time();
        data->philos[i].start_time = get_current_time();
        i++;
    }
}

void *death_monitor(void *arg)
{
    t_data *data = (t_data *)arg;
    while (1)
    {
        int i = 0;
        while (i < data->philo_num)
        {
            if (check_die(data, &data->philos[i]) || check_all_ate(data))
                return NULL;
            i++;
        }
        usleep(1000);
    }
}

void create_and_join_threads(t_data *data)
{
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, death_monitor, (void *)data);

    int i = 0;
    pthread_t *threads = malloc(data->philo_num * sizeof(pthread_t));
    while (i < data->philo_num)
    {
        pthread_create(&threads[i], NULL, routine, (void *)&data->philos[i]);
        i++;
    }

    i = 0;
    while (i < data->philo_num)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
    pthread_join(monitor_thread, NULL);
    free(threads);
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
    pthread_mutex_destroy(&data->check_death_mutex);
    pthread_mutex_destroy(&data->philo_can_eat);

    free(data->forks);
    free(data->philos);
    free(data);
}
 
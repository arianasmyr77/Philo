/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:41:07 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 15:35:14 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1) {
        if (philo->data->dead_flag) {
            break;
        }
        spageti_table_for_philos(philo);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    t_data *data;
    int i;
 
    if (argc != 5)
        return 1;

    data = (t_data *)malloc(sizeof(t_data));
    data->philo_num = ft_atoi(argv[1]);
    data->time_to_die  = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->time_each_philo_should_eat = ft_atoi(argv[5]);
    data->dead_flag = 0; 

    init_philos(data);

    i = 0;
    while (i < data->philo_num)
    {
        pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]);
        i++;
    }
    
    for (i = 0; i < data->philo_num; i++) {
        pthread_join(data->philos[i].thread, NULL);
    }

    free_data(data);

    return (0);
}
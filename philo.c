/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:41:07 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/26 20:56:39 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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
    data->dead_flag = 0; 

    init_philos(data);

    i = 0;
    while (i < data->philo_num)
    {
        pthread_create(&data->philos[i].thread, NULL, goes_routina, &data->philos[i]);
        i++;
    }
    
    for (i = 0; i < data->philo_num; i++) {
        pthread_join(data->philos[i].thread, NULL);
    }

    free_data(data);

    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:41:07 by arforouz          #+#    #+#             */
/*   Updated: 2024/07/22 14:16:54 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    check_arguments(t)
{
    if (data->philo_num <= 0)
        return (1);
    else if (data->time_to_eat <= 0)
        return (1);
    else if (data->time_to_sleep <= 0)
        return (1);
    else if (data->time_to_think <= 0)
        return (1) ;
}

int main(int argc, char **argv)
{
    t_data *data;
    int i;
 
    if (argc < 5 || argc > 6)
    {
        printf("Incorrect number of arguments");
        //return 1;
        return EXIT_FAILURE;
    }
        
    //data = (t_data *)malloc(sizeof(t_data));
    data->philo_num = ft_atoi(argv[1]);
    data->time_to_die  = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->num_times_to_eat = (argc == 6) ? ft_atoi(argv[5]);
    data->dead_flag = 0; 

    // if (philo_num <= 0 || time_to_die <= 0 || time_to_eat <= 0 /
    // || time_to_sleep <= 0)
    // {
    //     printf("All  time values must be > 0\n ;-)\n please try again\n");
    //     return (1) ;
    // }
    init_philos(data);

    // i = 0;
    // while (i < data->philo_num)
    // {
    //     pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]);
    //     i++;
    // }
    
    // for (i = 0; i < data->philo_num; i++) {
    //     pthread_join(data->philos[i].thread, NULL);
    // }

    free_data(data);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:41:07 by arforouz          #+#    #+#             */
/*   Updated: 2024/07/25 13:37:04 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

// int    check_arguments(t_data *data)
// {
//     if (data->philo_num <= 0)
//         return (1);
//     else if (data->time_to_eat <= 0)
//         return (1);
//     else if (data->time_to_sleep <= 0)
//         return (1);
//     else if (data->time_to_think <= 0)
//         return (1);
// }

int main(int argc, char **argv)
{
    t_data *data;

    if (argc < 4 || argc > 6)
    {
        printf("Incorrect number of arguments");
        //return 1;
        return EXIT_FAILURE;
    }
        
    data = (t_data *)malloc(sizeof(t_data));
    if(data == NULL)
      return (1);
    data->philo_num = ft_atoi(argv[1]);
    data->time_to_die  = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
    {
        data->num_times_to_eat = ft_atoi(argv[5]);
    }
    else
        data->num_times_to_eat = -1;
    data->dead_flag = 0; 
    data->all_ate_enough = 0;
    data->start_time = get_current_time();
    // if (philo_num <= 0 || time_to_die <= 0 || time_to_eat <= 0 || time_to_sleep <= 0)
    // {
    //     printf("All  time values must be > 0\n ;-)\n please try again\n");
    //     return (1) ;
    // }
    init_data(data);
    create_and_join_threads(data);
    free_data(data);
    return (0);
}

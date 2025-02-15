/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:41:07 by arforouz          #+#    #+#             */
/*   Updated: 2024/09/13 19:13:10 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int check_arguments(t_data *data)
{
    if (data->philo_num <= 0 || data->philo_num > 200)
    {
        printf("The number of philosophers must be between 1 and 200.\n");
        return (1);
    }
    if (data->time_to_die < 60 || data->time_to_eat < 60 || data->time_to_sleep < 60)
    {
        printf("Time values (to die, to eat, to sleep) must be at least 60 ms.\n");
        return (1);
    }
    if (data->num_times_to_eat < -1)
    {
        printf("The number of times to eat can't be negative.\n");
        return (1);
    }
    return (0);
}

t_data *parse_arguments(int argc, char **argv)
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    if (argc < 4 || argc > 6)
    {
        printf("Incorrect number of arguments");
        return (NULL);
    }
    data->philo_num = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    //data->num_times_to_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
    if (argc == 6)
        data->num_times_to_eat = ft_atoi(argv[5]);
    else
        data->num_times_to_eat = -1;
    data->dead_flag = 0;
    data->all_ate_enough = 0;
    data->start_time = get_current_time();
    return data;
}

int main(int argc, char **argv)
{
    t_data *data;

    data = parse_arguments(argc, argv);
    if (data == NULL)
        return EXIT_FAILURE;
    if (check_arguments(data))
    {
        free(data);
        return EXIT_FAILURE;
    }
    init_data(data);
    create_and_join_threads(data);
    free_data(data);

    return (0);
}

// int check_arguments(t_data *data)
// {
//     if (data->philo_num <= 0 || data->philo_num > 200)
//     {
//         printf("The value must be > 0\n ;-)\n please try again\n");
//         printf("You can't test with more than 200 Philosophers\n");
//         return (1);
//     }
//     if ((data->time_to_eat || data->time_to_sleep || 
//data->time_to_think) < 60)
//     {
//         printf("The value can't be less than 60");
//         return (1);
//     }
// }
// int	main(int argc, char **argv)
// {
// 	t_data	*data;

//     if (argc < 4 || argc > 6)
//     {
//         printf("Incorrect number of arguments");
//         //return 1;
//         return EXIT_FAILURE;
//     }
        
//     data = (t_data *)malloc(sizeof(t_data));
//     if(data == NULL)
//       return (1);
//     data->philo_num = ft_atoi(argv[1]);
//     data->time_to_die  = ft_atoi(argv[2]);
//     data->time_to_eat = ft_atoi(argv[3]);
//     data->time_to_sleep = ft_atoi(argv[4]);
//     if (argc == 6)
//     {
//         data->num_times_to_eat = ft_atoi(argv[5]);
//     }
//     else
//         data->num_times_to_eat = -1;
//     data->dead_flag = 0; 
//     data->all_ate_enough = 0;
//     data->start_time = get_current_time();
//     // if (philo_num <= 0 || time_to_die <= 0 || time_to_eat <= 0 || time_to_sleep <= 0)
//     // {
//     //     printf("All  time values must be > 0\n ;-)\n please try again\n");
//     //     return (1) ;
//     // }
//     init_data(data);
//     create_and_join_threads(data);
//     free_data(data);
//     return (0);
// }

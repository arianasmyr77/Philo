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
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 4 || argc > 6)
	{
		printf("Incorrect number of arguments");
		return (1);
	}
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
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
	//check_arguments(data);
	create_and_join_threads(data);
	check_die(data, data->philos);
	free_data(data);
	return (0);
}

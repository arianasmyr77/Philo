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

int	check_arguments(t_data *data)
{
	if (data->philo_num <= 0 || data->philo_num > 200)
	{
		printf("The number of philosophers must be between 1 and 200.\n");
		return (1);
	}
	if (data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60)
	{
		printf("Values(to die, to eat, to sleep) must be at least 60ms.\n");
		return (1);
	}
	if (data->num_times_to_eat < -1)
	{
		printf("The number of times to eat can't be negative.\n");
		return (1);
	}
	return (0);
}

static t_data	*parse_arguments(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (argc < 4 || argc > 6)
	{
		printf("Incorrect number of arguments");
		free (data);
		return (NULL);
	}
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_times_to_eat = ft_atoi(argv[5]);
	else
		data->num_times_to_eat = -1;
	data->dead_flag = 0;
	data->all_ate_enough = 0;
	data->start_time = get_current_time();
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = parse_arguments(argc, argv);
	if (!data)
		return (1);
	if (check_arguments(data))
	{
		free(data);
		return (1);
	}
	if (init_data(data) != 0)
	{
		free(data);
		return (1);
	}
	if (init_threads(data) != 0)
	{
		free_data(data);
		return (1);
	}
	free_data(data);
	return (0);
}

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

int	check_arguments(char **argv)
{
	if (!ft_isdigit(argv[1]))
	{
		printf("Incorrect Value for number of philos\n");
		return (1);
	}
	if (!ft_isdigit(argv[2]) || !ft_isdigit(argv[3]) || !ft_isdigit(argv[4]))
	{
		printf("Incorrect time values\n");
		printf("check Time to die , eat and sleep then try again please\n");
		return (1);
	}
	if (argv[5] && !ft_isdigit(argv[5]))
	{
		printf("Incorrect value for times to eat\n");
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
	if (argc < 5 || argc > 6)
	{
		printf("Incorrect number of arguments\n");
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
	if (check_arguments(argv))
		return (1);
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

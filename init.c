/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:29 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/13 18:35:54 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_data(t_data *philo)
{
    t_philo->philo_num = ft_atoi(argv[1]);
    t_philo->time_to_die  = ft_atoi(argv[2]);
    t_philo->time_to_eat = ft_atoi(argv[3]);
    t_philo->time_to_sleep = ft_atoi(argv[4]);
}


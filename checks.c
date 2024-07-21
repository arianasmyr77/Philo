/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:54:16 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 16:08:31 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    check_arguments()
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

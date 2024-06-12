/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:43:39 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/12 21:14:55 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data
{
    int     num_philos;
    long long    time_t tv_sec;  :-/??
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     time_to_think;
} t_data;

typedef struct s_philo
{
    int id;
    int l_fork;
    int r_fork;
    

} t_philo;
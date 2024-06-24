/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:43:39 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/24 12:58:48 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

typedef struct s_data
{
    int     philo_num;
    long start_time;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_to_think;
    long long    time_t tv_sec;  :-/??
    
} t_data;

typedef struct s_philo
{
    int pos;
    int id;
    int l_fork;
    int r_fork;
    int philo_id;
    int dead_flag;

} t_philo;
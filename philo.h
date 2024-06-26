/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:43:39 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/26 20:37:52 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

# define Take_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

typedef struct s_data
{
    int     philo_num;
    long start_time;
    int death_time;
    int time_to_eat;
    int time_to_sleep;
    int time_to_think;
    int dead_flag;
    t_philo     *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
    pthread_mutex_t check_breaker; //wtf gpt
    pthread_mutex_t check_final_eating;//what the fuk chatgpt
} t_data;

typedef struct s_philo
{
    struct s_data   *data;
    int pos;
    int id;
    int l_fork;
    int r_fork;
    int dead_flag;

} t_philo;
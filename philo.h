/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:43:39 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/27 15:34:49 by arforouz         ###   ########.fr       */
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

typedef struct s_philo
{
    struct s_data   *data;
    int pos;
    int id;
    int l_fork;
    int r_fork;
    pthread_t thread;
    int dead_flag;

} t_philo;

typedef struct s_data
{
    int     philo_num;
    long start_time;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int time_to_think;
    int time_each_philo_should_eat;
    int dead_flag;
    
    t_philo     *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
    pthread_mutex_t check_breaker;
    pthread_mutex_t check_final_eating;
} t_data;

//init.c
void    init_philos(t_data *data);

//actions.c
void spageti_table_for_philos(t_philo *philo);

//utils.c
void print_action(t_philo *philo, const char *action);
void    free_data(t_data *data);
int	    ft_atoi(const char *str);
void    ft_usleep(long time_in_ms);

//philo.c
void *goes_routina(void *arg);

#endif
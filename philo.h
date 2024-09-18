/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:43:39 by arforouz          #+#    #+#             */
/*   Updated: 2024/08/08 14:23:30 by arforouz         ###   ########.fr       */
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
# define DEAD "has died"

typedef struct s_philo
{
    struct s_data   *data;
    int id;
    int l_fork;
    int r_fork;
    int times_eaten;
    int dead_flag;
    long last_eat;
    long start_time;
    pthread_t thread;
} t_philo;

typedef struct s_data
{
    int     philo_num;
    long    start_time;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     time_to_think;
    int     num_times_to_eat;
    int     all_ate_enough;
    int     dead_flag;
    
    t_philo         *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
    pthread_mutex_t check_death_mutex;
    pthread_mutex_t philo_can_eat;
} t_data;

//init.c
void    init_data(t_data *data);
void    create_and_join_threads(t_data *data);
void    free_data(t_data *data);

//actions.c
void *routine(void *arg);

//checks 
int all_philos_ate_enough(t_data *data);
int is_any_philo_dead(t_data *data);
int check_die(t_data *data, t_philo *philo);
int check_all_ate(t_data *data);

//utils.c
long    get_current_time(void);
int	    ft_atoi(const char *str);
int	    ft_usleep(size_t millisec);
void    print_action(t_philo *philo, const char *action);
void    *monitor_routine(void *arg);
#endif
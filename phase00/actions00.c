/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:54:59 by arforouz          #+#    #+#             */
/*   Updated: 2024/07/22 13:14:02 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int times_eaten;
    int id;
    int l_fork;
    int r_fork;
    int last_eat;
    // pthread_mutex_t	*r_fork;
	// pthread_mutex_t	*l_fork;
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
    int num_times_to_eat;
    int dead_flag;
    
    t_philo     *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t message;
    pthread_mutex_t death_mutex;
    pthread_t         any_dead_philo;
    pthread_mutex_t check_final_eating;
} t_data;

//from utils
long     get_current_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}


void ft_usleep(long time_in_ms)
{
    long start_time = get_current_time();
    long end_time = start_time + time_in_ms;

    while (get_current_time() < end_time)
        usleep(100); // Sleep for a short duration to prevent busy-waiting
}

void print_action(t_philo *philo, const char *action)
{
    t_data *data = philo->data;
    time_t time;
    
    time = get_current_time() - data->start_time;
    pthread_mutex_lock(&data->message);
    printf("[%ld ms] Philosopher %d %s\n", time, philo->id, action);
    pthread_mutex_unlock(&data->message);
}


//check for dead_flag
int check_philo_death(t_data *data)
{
    int any_dead;

    pthread_mutex_lock(&(data->death_mutex));
    any_dead = data->death_mutex;
    pthread_mutex_unlock(&(data->death_mutex));
    return (any_dead);
}


int check_die(t_data *data, t_philo *philo, int check_any)
{
    int time;

    if (check_any)
    {
        if (check_philo_death(data))
            return (1);
    }

    time = get_time(data);
    if (time - philo->last_eat > data->time_to_die)
    {
        print_action(philo, DEAD);
        return (1);
    }
    return (0);
}
void    think_time(t_philo *philo)
{

    t_data  *data;

    data = philo->data;
    print_action(philo, THINK);
    ft_usleep(1);
}

void spageti_table_for_philos(t_philo *philo)
{
    t_data  *data;

    data = philo->data;
    pthread_mutex_lock(&data->forks[philo->l_fork]);
    print_action(philo, Take_FORK);
    pthread_mutex_lock(&data->forks[philo->r_fork]);
    print_action(philo, Take_FORK);
    print_action(philo, EAT);
    usleep(data->time_to_eat * 1000);
    pthread_mutex_unlock(&data->forks[philo->l_fork]);
    pthread_mutex_unlock(&data->forks[philo->r_fork]);
}

void  sleep_time(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    print_action(philo, SLEEP);
    ft_usleep(data->time_to_sleep);
}
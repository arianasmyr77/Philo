/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsomething.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:01:31 by arforouz          #+#    #+#             */
/*   Updated: 2024/07/10 15:05:42 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the structure for philosopher
typedef struct s_philo {
    int id;
    int l_fork;
    int r_fork;
    long time_to_eat;
    long time_to_sleep;
    long time_to_think;
    pthread_t thread;
    pthread_mutex_t *forks;
    pthread_mutex_t *message_mutex;
} t_philo;

// Function prototypes
void *philo_routine(void *arg);
void perform_action(const char *action, t_philo *philo, long duration);

int main() {
    int philo_num = 5;
    long time_to_eat = 1000;  // 1 second
    long time_to_sleep = 2000; // 2 seconds
    long time_to_think = 500;  // 0.5 second

    // Allocate resources
    pthread_mutex_t forks[philo_num];
    pthread_mutex_t message_mutex = PTHREAD_MUTEX_INITIALIZER;
    t_philo philos[philo_num];

    // Initialize mutexes
    for (int i = 0; i < philo_num; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Initialize philosophers and create threads
    for (int i = 0; i < philo_num; i++) {
        philos[i].id = i;
        philos[i].l_fork = i;
        philos[i].r_fork = (i + 1) % philo_num;
        philos[i].time_to_eat = time_to_eat;
        philos[i].time_to_sleep = time_to_sleep;
        philos[i].time_to_think = time_to_think;
        philos[i].forks = forks;
        philos[i].message_mutex = &message_mutex;
        pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]);
    }

    // Join philosopher threads
    for (int i = 0; i < philo_num; i++) {
        pthread_join(philos[i].thread, NULL);
    }

    // Cleanup
    for (int i = 0; i < philo_num; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
    pthread_mutex_destroy(&message_mutex);

    return 0;
}

void *philo_routine(void *arg) {
    t_philo *philo = (t_philo *)arg;

    while (1) {
        // Thinking
        perform_action("thinking", philo, philo->time_to_think);

        // Take forks
        pthread_mutex_lock(&philo->forks[philo->l_fork]);
        pthread_mutex_lock(&philo->forks[philo->r_fork]);

        // Eating
        perform_action("eating", philo, philo->time_to_eat);

        // Put down forks
        pthread_mutex_unlock(&philo->forks[philo->r_fork]);
        pthread_mutex_unlock(&philo->forks[philo->l_fork]);

        // Sleeping
        perform_action("sleeping", philo, philo->time_to_sleep);
    }

    return NULL;
}

void perform_action(const char *action, t_philo *philo, long duration) {
    pthread_mutex_lock(philo->message_mutex);
    printf("Philosopher %d is %s.\n", philo->id, action);
    pthread_mutex_unlock(philo->message_mutex);
    usleep(duration * 1000);
}

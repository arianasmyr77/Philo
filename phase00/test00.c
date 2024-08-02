/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:32:33 by arforouz          #+#    #+#             */
/*   Updated: 2024/07/22 12:21:59 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

// Mutexes for forks
pthread_mutex_t forks[NUM_PHILOSOPHERS];

// Philosopher threads
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher(void *num) {
    int id = *((int *)num);

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);  // Simulate thinking

        // Pick up forks
        int left = id;
        int right = (id + 1) % NUM_PHILOSOPHERS;

        // Prevent deadlock by ensuring an order of picking up forks
        if (id % 2 == 0) {
            pthread_mutex_lock(&forks[left]);
            pthread_mutex_lock(&forks[right]);
        } else {
            pthread_mutex_lock(&forks[right]);
            pthread_mutex_lock(&forks[left]);
        }

        printf("Philosopher %d is eating.\n", id);
        sleep(1);  // Simulate eating

        // Put down forks
        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);

        printf("Philosopher %d finished eating.\n", id);
    }

    return NULL;
}

int main() {
    int i;
    int ids[NUM_PHILOSOPHERS];

    // Initialize the mutexes for forks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for philosopher threads to finish (they won't in this example)
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy the mutexes for forks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// #define NUM_PHILOSOPHERS 5

// pthread_mutex_t forks[NUM_PHILOSOPHERS];
// pthread_t philosophers[NUM_PHILOSOPHERS];
// pthread_mutex_t death_mutex;
// time_t last_meal[NUM_PHILOSOPHERS];

// void *philosophers(void *num)
// {
//     int id = *((int *)num);

//     while (1)
//     {
//         pthread_mutex_lock(&death_mutex);
//         time_t current_time = time[NULL];
//         if (difftime(current_time, last_meal[id]) > TIME_LIMIT) {
//             printf("Philosopher %d is dead end of the game.\n", id);
//         }
//         pthread_mutex_unlock(&access_time);
//         printf("Philo %d is thinking.\n", id);
//         sleep(1);

//         int left = id;
//         int right = (id + 1) % NUM_PHILOSOPHERS;

//         if (id %% 2 == 0)
//         {
//             pthread_mutex_lock(&forks[left]);
//             pthread_mutex_lock(&forks[right]);
//         }
//         else
//         {
//             pthread_mutex_lock(&forks[right]);
//             pthread_mutex_lock(&forks[left]);
//         }

//         printf("Philo %d is eating\n", id);
//         sleep(1);

//         pthread_mutex_unlock(&forks[left]);
//         pthread_mutex_unlock(&forks[right]);

//         printf("Philo %d is sleeping\n", id);
//     }
//     return NULL;
// }

// int main()
// {
//     int i;
//     int ids[NUM_PHILOSOPHERS];

//     i = 0;
//     for (i = 0; i < NUM_PHILOSOPHERS; i++;)
//     {
//         pthread_mutex_init(&forks[i], NULL);
//     }
//     i = 0;
//     for (i = 0; i < NUM_PHILOSOPHERS; i++;)
//     {
//         ids[i] = i;
//         pthread_create(&philosophers[i], NULL, philospher, &ids[i]);
//     }
//     for (i = 0; i < NUM_PHILOSOPHERS; i++;)
//     {
//         pthread_mutex_destroy(&forks[i]);
//     }
//     return 0;
// }
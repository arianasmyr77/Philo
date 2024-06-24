/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:45:27 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/24 13:32:05 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>

long     get_current_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void print_action(int philo_id, const char *action)
{
    printf("◦ %ld %d %s\n", get_current_time(), philo_id, action);
}
int main() {
    // Get and print the current time in milliseconds
    long long current_time_ms = get_current_time();
    printf("Current time in milliseconds since the Epoch: %lld\n", current_time_ms);
    return 0;
}
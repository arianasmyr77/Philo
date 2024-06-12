/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:13:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/12 21:43:19 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

/*The struct timeval is a structure defined in the <sys/time.h> header file,
 which is used to represent time. It has the following definition:*/
// struct timeval {
//     long tv_sec;  /* seconds */
//     long tv_usec; /* microseconds */
// };


long get_current_time(void)
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

/*When you want to represent the current time in milliseconds, you need to convert 
both seconds and microseconds into a single unit of milliseconds.
There are 1,000,000 microseconds in a second.
There are 1000 microseconds in a millisecond.*/

int main() {
    // Get and print the current time in milliseconds
    long long current_time_ms = get_current_time();
    printf("Current time in milliseconds since the Epoch: %lld\n", current_time_ms);
    return 0;
}
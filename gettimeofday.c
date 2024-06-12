/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:13:06 by arforouz          #+#    #+#             */
/*   Updated: 2024/06/12 20:47:56 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int current_time(struct timeval *tv, struct timezone *tz)
{
    struct timeval start;

    gettimeofday(&start, NULL);
}
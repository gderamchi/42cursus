/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:21:39 by guillaume_d       #+#    #+#             */
/*   Updated: 2026/01/05 10:03:14 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	print_status_line(t_status status, long elapsed, int id)
{
	if (status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		printf("%ld %d has taken a fork\n", elapsed, id);
	else if (status == EATING)
		printf("%ld %d is eating\n", elapsed, id);
	else if (status == SLEEPING)
		printf("%ld %d is sleeping\n", elapsed, id);
	else if (status == THINKING)
		printf("%ld %d is thinking\n", elapsed, id);
	else if (status == DIED)
		printf("%ld %d died\n", elapsed, id);
}

void	write_status(t_status status, t_philo *philo)
{
	long	elapsed;
	long	start;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (simulation_finished(philo->table))
	{
		safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
		return ;
	}
	start = get_long(&philo->table->table_mutex,
			&philo->table->start_simulation);
	elapsed = gettime(MILLISECOND) - start;
	print_status_line(status, elapsed, philo->id);
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}

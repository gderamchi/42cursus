/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 00:00:00 by guillaume_d       #+#    #+#             */
/*   Updated: 2026/01/05 10:03:14 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static bool	all_philos_full(t_table *table)
{
	int		i;
	t_philo	*philo;

	if (table->nbr_limit_meals <= 0)
		return (false);
	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = &table->philos[i];
		if (!get_bool(&philo->philo_mutex, &philo->full))
			return (false);
	}
	return (true);
}

static void	announce_death(t_philo *philo)
{
	long	elapsed;
	long	start;

	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	safe_mutex_handle(&philo->table->table_mutex, LOCK);
	if (!philo->table->end_simulation)
	{
		philo->table->end_simulation = true;
		safe_mutex_handle(&philo->table->table_mutex, UNLOCK);
		start = get_long(&philo->table->table_mutex,
				&philo->table->start_simulation);
		elapsed = gettime(MILLISECOND) - start;
		printf("%ld %d died\n", elapsed, philo->id);
	}
	else
		safe_mutex_handle(&philo->table->table_mutex, UNLOCK);
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}

static bool	scan_for_death(t_table *table)
{
	int		i;
	t_philo	*philo;
	long	last_meal;

	i = -1;
	while (++i < table->philo_nbr && !simulation_finished(table))
	{
		philo = &table->philos[i];
		if (get_bool(&philo->philo_mutex, &philo->full))
			continue ;
		last_meal = get_long(&philo->philo_mutex, &philo->last_meal_time);
		if (gettime(MILLISECOND) - last_meal >= table->time_to_die)
		{
			announce_death(philo);
			return (true);
		}
	}
	return (false);
}

void	*monitor_simulation(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	wait_all_threads(table);
	while (!simulation_finished(table))
	{
		if (all_philos_full(table))
		{
			set_bool(&table->table_mutex, &table->end_simulation, true);
			break ;
		}
		if (scan_for_death(table))
			break ;
		usleep(1000);
	}
	return (NULL);
}

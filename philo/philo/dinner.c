/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 07:41:58 by guillaume_d       #+#    #+#             */
/*   Updated: 2026/01/05 12:50:40 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	thinking(t_philo *philo)
{
	long	think_ms;

	write_status(THINKING, philo);
	if (philo->table->philo_nbr % 2 == 1)
	{
		think_ms = (philo->table->time_to_die - (philo->table->time_to_eat
					+ philo->table->time_to_sleep)) / 2;
		if (think_ms > 0)
			precise_usleep(think_ms * 1000, philo->table);
	}
}

static void	eat(t_philo *philo)
{
	safe_mutex_handle(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo);
	if (philo->first_fork == philo->second_fork)
	{
		precise_usleep(philo->table->time_to_die * 1000, philo->table);
		safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
		return ;
	}
	safe_mutex_handle(&philo->second_fork->fork, LOCK);
	safe_mutex_handle(&philo->philo_mutex, LOCK);
	philo->last_meal_time = gettime(MILLISECOND);
	philo->meals_counter++;
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == philo->table->nbr_limit_meals)
		philo->full = true;
	safe_mutex_handle(&philo->philo_mutex, UNLOCK);
	write_status(TAKE_SECOND_FORK, philo);
	write_status(EATING, philo);
	precise_usleep(philo->table->time_to_eat * 1000, philo->table);
	safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
	safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	if (philo->table->philo_nbr > 1 && philo->id % 2 == 0)
		precise_usleep((philo->table->time_to_eat * 1000) / 2, philo->table);
	if (philo->first_fork == philo->second_fork)
	{
		safe_mutex_handle(&philo->first_fork->fork, LOCK);
		write_status(TAKE_FIRST_FORK, philo);
		precise_usleep(philo->table->time_to_die * 1000, philo->table);
		safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
		return (NULL);
	}
	while (!simulation_finished(philo->table))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_status(SLEEPING, philo);
		precise_usleep(philo->table->time_to_sleep * 1000, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	dinner_start(t_table *table)
{
	int			i;
	pthread_t	monitor_thread;
	long		start;

	i = -1;
	if (table->nbr_limit_meals == 0)
		return ;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
			&table->philos[i], CREATE);
	safe_thread_handle(&monitor_thread, monitor_simulation, table, CREATE);
	start = gettime(MILLISECOND);
	set_long(&table->table_mutex, &table->start_simulation, start);
	i = -1;
	while (++i < table->philo_nbr)
		set_long(&table->philos[i].philo_mutex,
			&table->philos[i].last_meal_time, start);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philo_nbr)
		safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
	safe_thread_handle(&monitor_thread, NULL, NULL, JOIN);
}

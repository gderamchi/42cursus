/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 00:00:00 by guillaume_d       #+#    #+#             */
/*   Updated: 2026/01/05 09:44:37 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clean(t_table *table)
{
	int	i;

	if (table == NULL)
		return ;
	if (table->philos != NULL)
	{
		i = -1;
		while (++i < table->philo_nbr)
			safe_mutex_handle(&table->philos[i].philo_mutex, DESTROY);
		free(table->philos);
		table->philos = NULL;
	}
	if (table->forks != NULL)
	{
		i = -1;
		while (++i < table->philo_nbr)
			safe_mutex_handle(&table->forks[i].fork, DESTROY);
		free(table->forks);
		table->forks = NULL;
	}
	safe_mutex_handle(&table->write_mutex, DESTROY);
	safe_mutex_handle(&table->table_mutex, DESTROY);
}

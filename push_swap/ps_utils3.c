/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:02:46 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/03 16:19:30 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	bits;
	int	max_num;

	bits = 0;
	max_num = size - 1;
	while (max_num != 0)
	{
		max_num /= 2;
		bits++;
	}
	return (bits);
}

int	is_sorted(t_list *stack)
{
	long	tmp;

	if (!stack)
		return (1);
	while (stack->next)
	{
		tmp = stack->content;
		stack = stack->next;
		if (stack->content < tmp)
			return (0);
	}
	return (1);
}

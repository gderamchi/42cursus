/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:08:33 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/04 12:26:18 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 0)
		ra(stack_a);
	pb(stack_a, stack_b);
	while ((*stack_a)->index != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	error_handling(t_list **stack_a, int ac, char **av)
{
	t_list	*current;
	t_list	*search;

	if (check_int(ac, av))
	{
		ft_lstclear(stack_a);
		return (1);
	}
	current = *stack_a;
	while (current->next)
	{
		search = current->next;
		while (search)
		{
			if (search->content == current->content)
			{
				ft_printf("Error\n");
				ft_lstclear(stack_a);
				return (1);
			}
			search = search->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9' || atol(av[i]) > INT_MAX
				|| atol(av[i]) < INT_MIN)
			{
				ft_printf("Error\n");
				return (1);
			}
		}
	}
	return (0);
}

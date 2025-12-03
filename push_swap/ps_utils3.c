/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:02:46 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/03 21:00:18 by guillaume_d      ###   ########.fr       */
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

void	sort_three(t_list **stack_a)
{
	t_list	*node;

	node = *stack_a;
	if ((*stack_a)->index == 2)
		ra(stack_a);
	else if (node->next->index == 2)
		rra(stack_a);
	node = *stack_a;
	sa(stack_a);
}

void	rra(t_list **stack_a)
{
	t_list	*head;
	t_list	*current;
	t_list	*last;
	int		size;
	int		i;

	i = -1;
	size = ft_lstsize(*stack_a);
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	current = *stack_a;
	head = *stack_a;
	while (++i < size - 2)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = head;
	*stack_a = last;
	ft_printf("rra\n");
}

void	sa(t_list **stack_a)
{
	t_list	*current;
	t_list	*tmp;

	if (!(*stack_a) || !(*stack_a)->next || !stack_a)
		return ;
	current = *stack_a;
	tmp = (*stack_a)->next;
	current->next = tmp->next;
	tmp->next = current;
	*stack_a = tmp;
	ft_printf("sa\n");
}

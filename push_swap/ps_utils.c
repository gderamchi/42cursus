/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:40:26 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/03 17:12:47 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	current = *stack_a;
	head = *stack_a;
	*stack_a = current->next;
	while (current->next)
		current = current->next;
	current->next = head;
	head->next = NULL;
	ft_printf("ra\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (!(*stack_b))
		return ;
	current = *stack_b;
	*stack_b = current->next;
	ft_lstadd_front(stack_a, current);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	if (!(*stack_a))
		return ;
	current = *stack_a;
	*stack_a = current->next;
	ft_lstadd_front(stack_b, current);
	ft_printf("pb\n");
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_list	*head;

	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(size);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (ft_lstsize(*stack_b) > 0)
			pa(stack_a, stack_b);
	}
}

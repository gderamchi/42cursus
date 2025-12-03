/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:40:22 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/03 17:11:26 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_stack(int ac, char **av)
{
	int		i;
	long	num;
	t_list	*stack_a;
	t_list	*new_node;

	i = 0;
	stack_a = NULL;
	while (++i < ac)
	{
		num = atol((const char *)av[i]);
		new_node = ft_lstnew(num);
		if (!new_node)
		{
			ft_lstclear(&stack_a);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new_node);
	}
	return (stack_a);
}

void	bubble_sort(long *tab, int size)
{
	int		i;
	int		j;
	long	tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
	}
}

void	indexation(t_list **stack, long *tab, int size)
{
	int		i;
	t_list	*current;

	i = -1;
	while (++i < size)
	{
		current = *stack;
		while (tab[i] != current->content && current->next)
			current = current->next;
		current->index = i;
	}
}

void	index_stack(t_list **stack)
{
	long	*tab;
	int		i;
	int		size;
	t_list	*current;

	i = -1;
	size = ft_lstsize(*stack);
	current = *stack;
	tab = malloc(size * sizeof(long));
	if (!tab)
		return ;
	while (++i < size)
	{
		tab[i] = current->content;
		current = current->next;
	}
	bubble_sort(tab, size);
	indexation(stack, tab, size);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list *stack_b;

	stack_b = NULL;
	stack_a = create_stack(ac, av);
	if (is_sorted(stack_a))
		return 0;
	index_stack(&stack_a);
	radix_sort(&stack_a, &stack_b);
	return (0);
}

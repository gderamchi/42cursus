/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:21:12 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/10 12:04:45 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;

	head = NULL;
	node = NULL;
	tail = NULL;
	while (lst)
	{
		tail = node;
		node = malloc(sizeof(t_list));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		node->content = f(lst->content);
		node->next = NULL;
		if (!head)
			head = node;
		else
			tail->next = node;
		lst = lst->next;
	}
	return (head);
}

// int	main(void)
// {
// 	t_list	*test;
// 	int		i;

// 	i = 0;
// 	test = malloc(sizeof(t_list));
// 	if (!test)
// 		return (0);
// 	while (i < 5)
// 	{
// 		test->content = i * 10;
// 		test = test->next;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%p\n", (int *)test->content);
// 		test = test->next;
// 		i++;
// 	}
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:21:12 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/17 07:32:17 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*begin;

	res = malloc(sizeof(t_list) * (ft_lstsize(lst) + 1));
	if (!res)
		return (NULL);
	begin = res;
	while (lst != NULL)
	{
		res = f(lst);
		if (!res)
		{
			ft_lstclear(begin, del);
			return (NULL);
		}
		res = res->next;
		lst = lst->next;
	}
	res = NULL;
	return (res);
}

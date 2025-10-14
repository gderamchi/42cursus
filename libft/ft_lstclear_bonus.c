/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 13:21:54 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/12 19:14:57 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int	i;

	i = 0;
	while (lst[i] != NULL)
	{
		del(lst[i]);
		free(lst[i]);
		i++;
	}
	lst = NULL;
}

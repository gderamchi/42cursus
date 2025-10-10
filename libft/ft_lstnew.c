/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:29:20 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/10 19:40:33 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

// int	main(void)
// {
// 	printf("%zu", sizeof(t_list));
// 	return (0);
// }

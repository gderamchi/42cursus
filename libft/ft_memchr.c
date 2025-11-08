/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:39:07 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/08 13:47:54 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = {0, 1, 2, 3, 4, 5};

// 	printf("%p\n", (char *)ft_memchr(s, 2, 3));
// 	printf("%p\n", (char *)memchr(s, 2, 3));
// 	return (0);
// }

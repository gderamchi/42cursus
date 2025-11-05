/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:39:07 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/04 19:03:17 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	while (*ptr && i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	if (*ptr == (unsigned char)c && i < n)
		return ((void *)ptr);
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Salut fdp comment tu vas";
// 	printf("%s\n", (char *)ft_memchr(str, 's', ft_strlen(str)));
// 	printf("%s\n", (char *)memchr(str, 's', ft_strlen(str)));
// 	return (0);
// }

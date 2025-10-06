/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:39:07 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 17:37:32 by guillaume_d      ###   ########.fr       */
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
		if (*ptr == c)
			return ((char *)ptr);
		ptr++;
		i++;
	}
	if (*ptr == c && i < n)
		return ((char *)ptr);
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

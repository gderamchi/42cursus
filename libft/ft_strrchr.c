/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:37:37 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/08 14:04:06 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*last;

	last = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			last = (unsigned char *)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		last = (unsigned char *)s;
	return ((char *)last);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "aabebdahsbz";
// 	printf("%s\n", ft_strrchr(str, 'c'));
// 	return (0);
// }

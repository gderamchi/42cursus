/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:32:57 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/08 14:07:55 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	j = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && k < len)
		{
			j++;
			k++;
		}
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char *str2;

// 	str = "";
// 	str2 = "";
// 	printf("%s\n", ft_strnstr(str, str2, ft_strlen(str)));
// 	printf("%s\n", strnstr(str, str2, ft_strlen(str)));
// 	return (0);
// }

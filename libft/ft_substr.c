/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:00:47 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/05 10:52:25 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_to_malloc;
	char	*res;
	size_t	i;

	len_to_malloc = ft_strlen((char *)s) - start;
	i = 0;
	if (start > (unsigned int)ft_strlen((char *)s))
		return ("");
	if (len <= len_to_malloc)
		res = (char *)malloc(len + 1);
	else
		res = (char *)malloc(len_to_malloc + 1);
	if (!res)
		return (NULL);
	s += start;
	while (*s && i < len)
	{
		res[i] = *s;
		s++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main(void)
// {
// 	char *str = "";
// 	printf("%s\n", ft_substr(str, 100, 10));
// 	return (0);
// }

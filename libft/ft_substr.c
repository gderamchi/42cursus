/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:00:47 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/10 16:35:27 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	to_copy;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
	{
		res = (char *)malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	to_copy = s_len - (size_t)start;
	if (to_copy > len)
		to_copy = len;
	res = (char *)malloc(to_copy + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, to_copy + 1);
	return (res);
}

// int main(void)
// {
// 	char *str = "";
// 	printf("%s\n", ft_substr(str, 100, 10));
// 	return (0);
// }

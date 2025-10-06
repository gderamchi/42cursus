/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:33:31 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 18:40:31 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	s1len;
	char			*res;

	s1len = ft_strlen((char *)s1);
	res = (char *)malloc(sizeof(char) * (s1len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, s1len + 1);
	return (res);
}

// int main()
// {
// 	printf("my strdup = %s\n", ft_strdup("`dslndsJGBNDSkjbjkBGNkj;"));
// 	printf("strdup = %s\n", strdup("kjggkbdsjkGBDSk;jghdsku;GH;hdg"));
// 	return 0;
// }

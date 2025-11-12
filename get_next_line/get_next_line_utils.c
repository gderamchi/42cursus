/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:41 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/11 21:54:18 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srclen;
	unsigned int	dstlen;
	unsigned int	size;

	i = 0;
	j = 0;
	srclen = ft_strlen((char *)src);
	dstlen = ft_strlen(dst);
	size = dstsize - dstlen - 1;
	if (dstlen >= dstsize || dstsize == 0)
		return (dstsize + srclen);
	while (dst[i])
		i++;
	while (j < size && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (srclen + dstlen);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	srclen;

	size = dstsize - 1;
	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		total;

	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(total);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, total);
	return (res);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

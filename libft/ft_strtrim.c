/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 01:01:55 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/05 12:42:32 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		char_from_end;
	int		char_from_start;
	int		len;
	int		final_alloc;

	len = ft_strlen((char *)s1);
	char_from_end = 0;
	char_from_start = 0;
	while (is_in_set(set, s1[char_from_start]))
		char_from_start++;
	s1 += len - 1;
	while (is_in_set(set, *s1) && ++char_from_end)
		s1--;
	s1 = s1 - (len - 1 - char_from_end) + char_from_start;
	final_alloc = len - (char_from_end + char_from_start);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	char_from_end = 0;
	while (char_from_end < final_alloc)
		res[char_from_end++] = *s1++;
	res[char_from_end] = '\0';
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim(" asamirosiosi ah", " "));
// 	return (0);
// }

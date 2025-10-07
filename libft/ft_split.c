/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:57 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/08 01:54:48 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**result(char **res, char const *s, char c)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		res[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!res[j])
			return (NULL);
		i -= len;
		ft_strlcpy(res[j++], &s[i], len + 1);
		i += len;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	res = (char **)malloc(sizeof(char *) * (words + 1));
	return (result(res, s, c));
}

// int	main(int ac, char **av)
// {
// 	if (ac != 3)
// 		return (0);
// 	printf("%s\n", ft_split(av[1], av[2][0])[8]);
// 	return (0);
// }

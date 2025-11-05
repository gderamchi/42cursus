/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:39:57 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/05 16:03:22 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_characters(int *i, const char *s, int *len, char c)
{
	while (s[*i] == c && s[*i])
		(*i)++;
	while (s[*i] != c && s[*i])
	{
		(*i)++;
		(*len)++;
	}
}

static char	**result(char **res, char const *s, char c)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		skip_characters(&i, s, &len, c);
		if (len > 0)
		{
			res[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!res[j])
				return (NULL);
			i -= len;
			ft_strlcpy(res[j++], &s[i], len + 1);
		}
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
	if (!res)
		return (NULL);
	return (result(res, s, c));
}

// int	main(int ac, char **av)
// {
// 	int	i;

// 	if (ac != 3)
// 		return (0);
// 	i = 0;
// 	while (i < 6)
// 		printf("%s\n", ft_split(av[1], av[2][0])[i++]);
// 	return (0);
// }

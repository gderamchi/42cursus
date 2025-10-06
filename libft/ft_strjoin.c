/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:51:50 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 15:09:42 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strslen(char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
			j++;
		i++;
	}
	return (j);
}

char	*ft_strjoin(char **input, char *sep)
{
	int	seplen;
	int	strslen;

	seplen = ft_strlen(sep);
	strslen = ft_strslen(input);
}

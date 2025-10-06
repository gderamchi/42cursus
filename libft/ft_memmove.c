/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:20:32 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 15:10:35 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int	i;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst2 == src2 || len == 0)
		return (dst);
	if (dst2 < src2)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			dst2[len] = src2[len];
	}
	return (dst2);
}

// #define ELEMENT_COUNT 10

// int	main(void)
// {
// 	int	data[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 0};

// 	// print before
// 	for (int i = 0; i < ELEMENT_COUNT; ++i)
// 		printf("%d ", data[i]);
// 	puts("");
// 	// shift right by one position (safe)
// 	ft_memmove(data + 1, data, (ELEMENT_COUNT - 1) * sizeof *data);
// 	// now insert new head
// 	data[0] = 10;
// 	// print after: 10 20 30 40 50 60 70 80 90 100
// 	for (int i = 0; i < ELEMENT_COUNT; ++i)
// 		printf("%d ", data[i]);
// 	puts("");
// 	return (EXIT_SUCCESS);
// }

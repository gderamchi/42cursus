/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:20:32 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/10 16:53:15 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = dst;
	temp2 = (unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
		while (len--)
			temp1[len] = temp2[len];
	return (dst);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:28:19 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/04 20:02:02 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (n == 0 || !src)
		return (dst);
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	int				array[] = {54, 85, 20, 63, 21};
// 	int				*array2;
// 	unsigned int	size;
// 	int				length;

// 	array2 = NULL;
// 	size = sizeof(int) * 5;
// 	/* Display the initial values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", array[length]);
// 	}
// 	printf("\n");
// 	/* Reset the memory bloc */
// 	ft_memcpy(array, array2, size);
// 	/* Display the new values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", array[length]);
// 	}
// 	printf("\n");
// 	return (0);
// }

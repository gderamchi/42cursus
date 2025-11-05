/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:59:05 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/04 17:21:08 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	int				array[] = {54, 85, 20, 63, 21};
// 	unsigned int	size;
// 	int				length;

// 	size = sizeof(int) * 5;
// 	/* Display the initial values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", array[length]);
// 	}
// 	printf("\n");
// 	/* Reset the memory bloc */
// 	ft_memset(array, -1, size);
// 	/* Display the new values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", array[length]);
// 	}
// 	printf("\n");
// 	return (0);
// }

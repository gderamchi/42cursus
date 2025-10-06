/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:59:05 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 15:10:31 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, unsigned int len)
{
	int				i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	if (len == 0)
		return (NULL);
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
// 	ft_memset(array, 0, size);
// 	/* Display the new values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", array[length]);
// 	}
// 	printf("\n");
// 	return (0);
// }

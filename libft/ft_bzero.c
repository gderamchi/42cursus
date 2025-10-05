/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:23:34 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/05 15:27:45 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

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
// 	ft_bzero(array, size);
// 	/* Display the new values */
// 	for (length = 0; length < 5; length++)
// 	{
// 		printf("%d ", array[length]);
// 	}
// 	printf("\n");
// 	return (0);
// }

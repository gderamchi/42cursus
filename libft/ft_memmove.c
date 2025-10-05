/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:20:32 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/05 16:57:17 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	*ft_memmove(void *dst, const void *src, unsigned int len)
// {

// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ELEMENT_COUNT 10

int	main(void)
{
	int		data[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 0};
	void	*source;
	void	*destination;
	size_t	size;

	// On crée une zone de mémoire de 10 entiers et contenant
	// que neuf valeurs. La dixième est non utilisée (0).
	// On affiche le contenu de la collection
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		printf("%d ", data[i]);
	}
	puts("\n"); // Un retour à la ligne
	// On décale les éléménts dans la collection ...
	source = (void *)data;
	destination = (void *)(data + 1);
	size = ELEMENT_COUNT * sizeof(int);
	memcpy(destination, source, size);
	// ... pour y insérer une nouvelle valeur en tête
	data[0] = 10;
	// On affiche le contenu de la collection
	for (int i = 0; i < ELEMENT_COUNT; i++)
	{
		printf("%d ", data[i]);
	}
	puts("\n"); // Un retour à la ligne
	return (EXIT_SUCCESS);
}

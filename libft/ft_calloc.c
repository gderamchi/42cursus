/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:59:14 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 18:31:14 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*p;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	memset(p, 0, total);
	return (p);
}
/*
static int	will_overflow(size_t count, size_t size)
{
	return (size != 0 && count > SIZE_MAX / size);
}

static void	test_case(const char *name, size_t count, size_t size)
{
	void	*o;
	void	*f;
	size_t	total;
	int		same;

	printf("\n=== %s ===\n", name);
	o = calloc(count, size);
	f = ft_calloc(count, size);
	total = count * (size ? size : 0);
	printf("calloc    : %s\n", o ? "OK (pointeur libérable)" : "NULL");
	printf("ft_calloc : %s\n", f ? "OK (pointeur libérable)" : "NULL");
	if (will_overflow(count, size))
	{
		// En cas d’overflow, on attend NULL des deux côtés
		printf("Attendu: NULL (overflow)\n");
		if (o == NULL && f == NULL)
			puts("✅ Cohérent");
		else
			puts("❌ Problème: au moins un n'est pas NULL");
	}
	else if (total == 0)
	{
		// Taille zéro: les deux comportements sont valides (NULL ou non-NULL)
		puts("ℹ️ Taille totale = 0 : valide");
		// pas de memcmp ni d’écriture !
	}
	else
	{
		// Taille > 0 : on vérifie que c'est zéro-initialisé
		if (o && f)
		{
			same = memcmp(o, f, total) == 0;
			printf("Comparaison mémoire (total=%zu): %s\n", total,
				same ? "identique ✅" : "différente ❌");
		}
		else
		{
			puts("❌ Un des deux est NULL alors que pas d’overflow et total > 0");
		}
	}
	free(o);
	free(f);
}

int	main(void)
{
	test_case("Normal (5 x sizeof(int))", 5, sizeof(int));
	test_case("count = 0", 0, sizeof(int));        // valide: NULL ou non-NULL
	test_case("size  = 0", 10, 0);                 // valide: NULL ou non-NULL
	test_case("overflow volontaire", SIZE_MAX, 2); // doit être NULL
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:13:18 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 15:10:07 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	srclen;

	size = dstsize - 1;
	i = 0;
	srclen = ft_strlen((char *)src);
	if (dstsize == 0)
		return (srclen);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// int main(void)
// {
//     char d_ref[32];
//     char d_ft[32];

//     // Liste des tests
//     const char *sources[] = {
//         "",
//         "abcdef",
//         "hello",
//         "abcdefghijklmnopqrstuvwxyz",
//         "héllø🌍"
//     };
//     size_t sizes[] = {16, 0, 1, 6, 5, 10, 32};

//     for (unsigned long s = 0; s < sizeof(sources)/sizeof(sources[0]); s++)
//     {
//         for (unsigned long z = 0; z < sizeof(sizes)/sizeof(sizes[0]); z++)
//         {
//             // Pré-remplir pour vérifier si des bytes sont écrasés
//             for (int i = 0; i < 32; i++) d_ref[i] = d_ft[i] = (char)0xCC;

//             size_t r_ref = strlcpy(d_ref, sources[s], sizes[z]);
//             size_t r_ft  = ft_strlcpy(d_ft,  sources[s], sizes[z]);

//             printf("SRC=\"%s\" SIZE=%zu\n", sources[s], sizes[z]);
//             printf("  return: ref=%zu  ft=%zu\n", r_ref, r_ft);
//             printf("  dst:    ref=\"%s\"  ft=\"%s\"\n\n", d_ref, d_ft);
//         }
//     }

//     return (0);
// }

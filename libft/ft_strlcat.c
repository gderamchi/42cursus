/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:42:19 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/06 15:05:00 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srclen;
	unsigned int	dstlen;
	unsigned int	size;

	i = 0;
	j = 0;
	srclen = ft_strlen((char *)src);
	dstlen = ft_strlen(dst);
	size = dstsize - dstlen - 1;
	if (dstsize == 0)
		return (srclen);
	while (dst[i])
		i++;
	while (i < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (srclen + dstlen);
}

// // int main(void)
// // {
// //     char d_ref[64];
// //     char d_ft[64];

// //     // Test cases
// //     const char *srcs[] = {
// //         "",
// //         "abcdef",
// //         "world",
// //         "abcdefghijklmnopqrstuvwxyz",
// //     };
// //     const char *dst_init[] = {
// //         "",
// //         "hello",
// //         "abc",
// //         "longexistingstring"
// //     };
// //     size_t sizes[] = {0, 1, 3, 5, 10, 20};

//     for (unsigned long d = 0; d < sizeof(dst_init)/sizeof(dst_init[0]); d++)
//     {
// //         for (unsigned long s = 0; s < sizeof(srcs)/sizeof(srcs[0]); s++)
// //         {
////    for (unsigned long z = 0; z < sizeof(sizes)/sizeof(sizes[0]); z++)
// //             {
// //                 // Fill both buffers with same initial dst content
// //                 memset(d_ref, 0, sizeof(d_ref));
// //                 memset(d_ft, 0, sizeof(d_ft));
// //                 strncpy(d_ref, dst_init[d], sizeof(d_ref) - 1);
// //                 strncpy(d_ft, dst_init[d], sizeof(d_ft) - 1);

// //                 size_t r_ref = strlcat(d_ref, srcs[s], sizes[z]);
// //                 size_t r_ft  = ft_strlcat(d_ft,  srcs[s], sizes[z]);

// //                 printf("DST=\"%s\" SRC=\"%s\" SIZE=%zu\n", dst_init[d],
// 	srcs[s], sizes[z]);
// //                 printf("  return: ref=%zu  ft=%zu  %s\n", r_ref, r_ft,
// 	(r_ref == r_ft ? "OK" : "MISMATCH"));
// //                 printf("  dst:    ref=\"%s\"  ft=\"%s\"\n\n", d_ref,
	// d_ft);
// //             }
// //         }
// //     }

// //     return (0);
// // }

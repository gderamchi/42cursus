/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:29 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/28 01:48:23 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*c;

	c = malloc(4);

	read(fd, c, 4);

	return ("ntm");
}
int	main(void)
{
	int	fd;

	fd = open("ntm.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}

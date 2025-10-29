/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:29 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/10/29 13:07:24 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[1024];
	char	ntm;
	int		i;
	char	*c;
	int		verif;

	i = 0;
	verif = read(fd, &ntm, 1);
	buffer[i++] = ntm;
	if (verif < 1)
		return (NULL);
	while (ntm != '\n' && ntm)
	{
		read(fd, &ntm, 1);
		buffer[i++] = ntm;
	}
	buffer[i] = '\0';
	c = malloc(sizeof(buffer));
	if (!c)
		return (NULL);
	i = -1;
	while (buffer[++i])
		c[i] = buffer[i];
	c[i] = '\0';
	return (c);
}

int	main(void)
{
	int	fd;

	fd = open("ntm.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}

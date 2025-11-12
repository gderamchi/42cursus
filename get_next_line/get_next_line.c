/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:29 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/12 12:01:18 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	to_copy;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
	{
		res = (char *)malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	to_copy = s_len - (size_t)start;
	if (to_copy > len)
		to_copy = len;
	res = (char *)malloc(to_copy + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, to_copy + 1);
	return (res);
}

char	*read_file(int fd, char *buffer)
{
	char	*tmp;
	int		nbytes;

	tmp = malloc(BUFFER_SIZE + 1);
	nbytes = 1;
	tmp[0] = '\0';
	while (nbytes > 0 && !ft_strchr(tmp, '\n'))
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes < 0)
			return (NULL);
		tmp[nbytes] = '\0';
		buffer = ft_strjoin(tmp, buffer);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*process_line(char *buffer)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(1);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i])
		i++;
	res = ft_substr(buffer, 0, i);
	if (!res)
		return (free(res), NULL);
	return (res);
}

char	*process_next(char *buffer)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (NULL);
	while (*buffer != '\n' && *buffer)
		buffer++;
	if (*buffer)
		buffer++;
	res = ft_substr(buffer, 0, ft_strlen(buffer));
	if (!res)
		return (free(res), NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = process_line(buffer);
	if (!line)
		return (free(line), NULL);
	buffer = process_next(buffer);
	if (!buffer)
		return (free(buffer), NULL);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("ntm.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }

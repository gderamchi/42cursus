/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:29 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/13 01:53:18 by guillaume_d      ###   ########.fr       */
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
	char	*new_buffer;
	int		nbytes;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
	{
		free(buffer);
		return (NULL);
	}
	nbytes = 1;
	while (nbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes < 0)
			return (free(buffer), free(tmp), NULL);
		tmp[nbytes] = '\0';
		new_buffer = ft_strjoin(buffer, tmp);
		if (!new_buffer)
			return (free(buffer), free(tmp), NULL);
		free(buffer);
		buffer = new_buffer;
	}
	free(tmp);
	return (buffer);
}


char	*process_line(char *buffer)
{
	int	i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

char	*process_next(char *buffer)
{
	int	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		return (NULL);
	return (ft_substr(buffer, i, ft_strlen(buffer + i)));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
	{
		buffer = NULL;
		return (NULL);
	}
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = process_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	next = process_next(buffer);
	free(buffer);
	buffer = next;
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

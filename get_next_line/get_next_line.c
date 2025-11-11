/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:29 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/11 18:47:16 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	s1len;
	char			*res;

	s1len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (s1len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, s1len + 1);
	return (res);
}

char	*process(int fd, char buf[], char *line, char **tmp)
{
	int		nbytes;
	char	*newline_pos;

	nbytes = 1;
	buf[0] = '\0';
	while (nbytes > 0 && !ft_strchr(buf, '\n'))
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		if (nbytes == 0)
			return (line);
		buf[nbytes] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			newline_pos = ft_strchr(buf, '\n');
			*tmp = ft_strdup(newline_pos + 1);
			*(newline_pos + 1) = '\0';
			line = ft_strjoin(line, buf);
			break ;
		}
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	line = ft_strdup("");
	tmp = NULL;
	if (!line)
		return (NULL);
	if (rest)
	{
		line = ft_strjoin(line, rest);
		free(rest);
		rest = NULL;
	}
	line = process(fd, buf, line, &tmp);
	rest = tmp;
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
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

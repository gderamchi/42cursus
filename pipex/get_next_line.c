/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:02:29 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/11/14 16:00:59 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		len;
	char	*next_str;

	if (!list)
		return (NULL);
	len = len_to_nl(list);
	next_str = malloc(len + 1);
	if (!next_str)
		return (NULL);
	copy_string(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buf)
{
	t_list	*new;
	t_list	*last;

	last = find_last_node(*list);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*list = new;
	else
		last->next = new;
	new->str_buf = buf;
	new->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	char	*buf;
	int		nbytes;

	while (!found_nl(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (!nbytes)
		{
			free(buf);
			return ;
		}
		buf[nbytes] = '\0';
		append(list, buf);
	}
}

void	polish_list(t_list **list)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(t_list));
	if (!buf || !clean)
		return ;
	last = find_last_node(*list);
	i = 0;
	j = 0;
	while (last->str_buf[i] != '\n' && last->str_buf[i])
		i++;
	while (last->str_buf[i] && last->str_buf[++i])
		buf[j++] = last->str_buf[i];
	buf[j] = '\0';
	clean->str_buf = buf;
	clean->next = NULL;
	dealloc(list, clean, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	polish_list(&list);
	return (next_line);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:37:55 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/16 13:43:17 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		total;

	total = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(total + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(res, s2, total);
	return (res);
}

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
	if (dstlen >= dstsize || dstsize == 0)
		return (dstsize + srclen);
	while (dst[i])
		i++;
	while (j < size && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (srclen + dstlen);
}

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
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

void	execute(char **envp, char *cmd, pid_t *pids)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args || !cmd_args[0])
		cmd_error(cmd_args, cmd, pids);
	cmd_path = find_path(envp, cmd_args[0]);
	if (!cmd_path)
		cmd_error(cmd_args, cmd_args[0], pids);
	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		free(cmd_path);
		cmd_error(cmd_args, cmd_args[0], pids);
	}
}

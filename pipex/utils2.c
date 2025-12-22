/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:01:52 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/22 18:24:56 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*extract_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + 5);
}

void	free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*find_path(char **envp, char *cmd)
{
	int		i;
	char	*path_value;
	char	**paths;
	char	*tmp;
	char	*full;

	path_value = extract_path(envp);
	if (!path_value)
		return (NULL);
	paths = ft_split(path_value, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
		{
			free_split(paths);
			return (full);
		}
		free(full);
	}
	free_split(paths);
	return (NULL);
}

int	verify_ffile(char **av)
{
	if (access(av[1], R_OK) < 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

void	open_outfile(t_pipex *px)
{
	if (ft_strncmp(px->av[1], "here_doc", 8) == 0)
	{
		px->out_fd = open(px->av[px->ac - 1], O_WRONLY | O_APPEND | O_CREAT,
				0644);
		if (px->out_fd < 0)
			cleanup_px(px);
	}
	else
	{
		px->out_fd = open(px->av[px->ac - 1], O_WRONLY | O_TRUNC | O_CREAT,
				0644);
		if (px->out_fd < 0)
			cleanup_px(px);
	}
}

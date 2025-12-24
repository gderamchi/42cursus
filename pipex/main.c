/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:37:53 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/22 11:20:01 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	is_limiter(char *line, char *limiter)
{
	int	len;

	if (!line)
		return (1);
	len = ft_strlen(limiter);
	if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
		return (1);
	return (0);
}

static void	write_here_doc(char *limiter, int fd)
{
	char	*line;

	while (1)
	{
		write(2, "here_doc>", 9);
		line = get_next_line(STDIN_FILENO);
		if (is_limiter(line, limiter))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
}

int	get_here_doc(char *limiter)
{
	int		fd;

	fd = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit(EXIT_FAILURE);
	write_here_doc(limiter, fd);
	gnl_clear();
	close(fd);
	fd = open(".heredoc_tmp", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	unlink(".heredoc_tmp");
	return (fd);
}

int	open_inf(t_pipex *px, int *i)
{
	if (ft_strncmp(px->av[1], "here_doc", 8) == 0)
	{
		if (px->ac < 6)
			cleanup_px(px);
		*i = 3;
		return (get_here_doc(px->av[2]));
	}
	*i = 2;
	px->in_fd = open(px->av[1], O_RDONLY);
	if (px->in_fd < 0)
	{
		perror(px->av[1]);
		px->in_fd = open("/dev/null", O_RDONLY);
	}
	return (px->in_fd);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;
	int		cmds;
	int		cmd_count;
	int		exit_status;

	if (ac < 5)
		return (EXIT_FAILURE);
	cmd_count = ac - 3;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		cmd_count = ac - 4;
	px.pids = malloc(sizeof(pid_t) * cmd_count);
	if (!px.pids)
		return (EXIT_FAILURE);
	px.ac = ac;
	px.av = av;
	px.envp = envp;
	px.in_fd = -1;
	px.out_fd = -1;
	px.pipe_fd[0] = -1;
	px.pipe_fd[1] = -1;
	cmds = launch_pipeline(&px);
	exit_status = wait_children(px.pids, cmds);
	free(px.pids);
	return (exit_status);
}

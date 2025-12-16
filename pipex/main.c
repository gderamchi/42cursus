/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:37:53 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/16 17:09:47 by guillaume_d      ###   ########.fr       */
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

void	here_doc_child(char *limiter, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		ft_printf("here_doc>");
		line = get_next_line(STDIN_FILENO);
		if (is_limiter(line, limiter))
		{
			free(line);
			close(fd[1]);
			exit(EXIT_SUCCESS);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
}

int	get_here_doc(char *limiter)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		here_doc_child(limiter, fd);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return (fd[0]);
}

int	open_inf(char **av, int ac, int *i)
{
	int	infile;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			exit(EXIT_FAILURE);
		*i = 3;
		return (get_here_doc(av[2]));
	}
	*i = 2;
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		exit(EXIT_FAILURE);
	return (infile);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	*pids;
	int		cmds;
	int		cmd_count;

	if (ac < 5)
		return (EXIT_FAILURE);
	cmd_count = ac - 3;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		cmd_count = ac - 4;
	pids = malloc(sizeof(pid_t) * cmd_count);
	if (!pids)
		return (EXIT_FAILURE);
	cmds = launch_pipeline(ac, av, envp, pids);
	wait_children(pids, cmds);
	free(pids);
	return (0);
}

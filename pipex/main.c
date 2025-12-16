/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:37:53 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/15 17:07:07 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void here_doc_child(char *limiter, int *fd)
{
	char *line;
	close(fd[0]);
	while (1)
	{
		ft_printf("here_doc>");
		line = get_next_line(0);
		if (!line)
			exit(EXIT_SUCCESS);
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_printf("%s", line);
		free(line);
	}
}

int get_here_doc(char *limiter)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
		here_doc_child(limiter, fd);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return (fd[0]);
}

int open_inf(char **av, int ac, int *i)
{
	int infile;

	infile = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		*i = 3;
		if (ac < 6)
			exit(1);
		get_here_doc(av[2]);
	}
	else
	{
		*i = 2;
		infile = open(av[1], O_RDONLY);
		if (infile < 0)
			exit(1);
	}
	return (infile);
}

void childloop(char *cmd, char **envp)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute(envp, cmd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

int main(int ac, char **av, char **envp)
{
	int i;
	int infile;
	int outfile;

	if (ac < 5)
		return (EXIT_FAILURE);
	infile = open_inf(av, ac, &i);
	dup2(infile, 0);
	close(infile);
	while (i < ac - 2)
		childloop(av[i++], envp);
	open_outfile(ac, av, &outfile);
	dup2(outfile, 1);
	close(outfile);
	execute(envp, av[ac - 2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:47:05 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/16 13:43:23 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

pid_t	spawn_child(char *cmd, char **envp, int in_fd, int out_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, 1) == -1)
			exit(EXIT_FAILURE);
		close(in_fd);
		close(out_fd);
		execute(envp, cmd);
	}
	return (pid);
}

void	wait_children(pid_t *pids, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

int	launch_pipeline(int ac, char **av, char **envp, pid_t *pids)
{
	int	fd[2];
	int	in_fd;
	int	i;
	int	cmds;

	in_fd = open_inf(av, ac, &i);
	cmds = 0;
	while (i < ac - 2)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);
		pids[cmds++] = spawn_child(av[i], envp, in_fd, fd[1]);
		close(fd[1]);
		close(in_fd);
		in_fd = fd[0];
		i++;
	}
	open_outfile(ac, av, &fd[1]);
	pids[cmds++] = spawn_child(av[ac - 2], envp, in_fd, fd[1]);
	close(in_fd);
	close(fd[1]);
	return (cmds);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
}

void	cmd_error(char **cmd_args, char *cmd)
{
	if (cmd_args)
		free_split(cmd_args);
	ft_printf("command not found: %s\n", cmd);
	exit(127);
}

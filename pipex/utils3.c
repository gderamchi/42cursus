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

pid_t	spawn_child(char *cmd, int in_fd, int out_fd, t_pipex *px)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, 1) == -1)
		{
			free(px->pids);
			exit(EXIT_FAILURE);
		}
		close(in_fd);
		close(out_fd);
		execute(cmd, px);
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

int	launch_pipeline(t_pipex *px)
{
	int	fd[2];
	int	in_fd;
	int	i;
	int	cmds;

	in_fd = open_inf(px->av, px->ac, &i);
	cmds = 0;
	while (i < px->ac - 2)
	{
		if (pipe(fd) == -1)
			exit(EXIT_FAILURE);
		px->pids[cmds++] = spawn_child(px->av[i], in_fd, fd[1], px);
		close(fd[1]);
		close(in_fd);
		in_fd = fd[0];
		i++;
	}
	open_outfile(px->ac, px->av, &fd[1]);
	px->pids[cmds++] = spawn_child(px->av[px->ac - 2], in_fd, fd[1], px);
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

void	cmd_error(char **cmd_args, char *cmd, t_pipex *px)
{
	write(2, "command not found: ", 19);
	if (cmd_args && cmd_args[0])
		write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	free_split(cmd_args);
	free(px->pids);
	exit(127);
}

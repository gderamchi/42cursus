/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:47:05 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/22 18:24:58 by guillaume_d      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

pid_t	spawn_child(char *cmd, t_pipex *px, int is_last)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		cleanup_px(px);
	if (pid == 0)
	{
		if (!is_last)
			close(px->pipe_fd[0]);
		if (dup2(px->in_fd, STDIN_FILENO) == -1 || dup2(px->out_fd,
				STDOUT_FILENO) == -1)
			cleanup_px(px);
		close(px->in_fd);
		close(px->out_fd);
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

void	cleanup_px(t_pipex *px)
{
	if (px->in_fd > 2)
		close(px->in_fd);
	if (px->out_fd > 2)
		close(px->out_fd);
	if (px->pipe_fd[0] > 2)
		close(px->pipe_fd[0]);
	if (px->pipe_fd[1] > 2)
		close(px->pipe_fd[1]);
	if (px->pids)
		free(px->pids);
	exit(EXIT_FAILURE);
}

int	launch_pipeline(t_pipex *px)
{
	int	i;
	int	cmds;

	px->in_fd = open_inf(px, &i);
	cmds = 0;
	while (i < px->ac - 2)
	{
		if (pipe(px->pipe_fd) == -1)
			cleanup_px(px);
		px->out_fd = px->pipe_fd[1];
		px->pids[cmds++] = spawn_child(px->av[i], px, 0);
		close(px->out_fd);
		close(px->in_fd);
		px->in_fd = px->pipe_fd[0];
		px->out_fd = -1;
		px->pipe_fd[1] = -1;
		i++;
	}
	open_outfile(px);
	px->pids[cmds++] = spawn_child(px->av[px->ac - 2], px, 1);
	close(px->in_fd);
	close(px->out_fd);
	return (cmds);
}

void	cmd_error(char **cmd_args, char *cmd, t_pipex *px)
{
	write(2, "command not found: ", 19);
	if (cmd_args && cmd_args[0])
		write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	free_split(cmd_args);
	if (px->pids)
		free(px->pids);
	exit(127);
}

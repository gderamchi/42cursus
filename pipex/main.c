/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume_deramchi <guillaume_deramchi@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:37:53 by guillaume_d       #+#    #+#             */
/*   Updated: 2025/12/05 13:24:19 by guillaume_d      ###   ########.fr       */
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
	if (access(av[4], X_OK) < 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

void	child1(int *fd, char **av, char **envp)
{
	int		infile_fd;
	char	**argv_cmd1;
	char	*path;

	infile_fd = open(av[1], O_RDONLY);
	dup2(infile_fd, 0);
	close(fd[0]);
	close(fd[1]);
	close(infile_fd);
	argv_cmd1 = ft_split(av[2], ' ');
	path = find_path(envp, argv_cmd1[0]);
	execve(path, argv_cmd1, envp);
}

void	child2(int *fd, char **av, char **envp);

void	forking(void);

void	duplicate(void);

void	piping(void);

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*path;

	if (ac != 5)
		return (0);
	if (verify_ffile(av))
		return (0);
	path = find_path(envp, av[2]);
	if (!path)
		return (0);
	if (pipe(fd) == -1)
		perror("pipe");
	pid1 = fork();
	if (pid1 == -1)
		perror("fork");
	if (pid1 == 0)
		child1(fd, av, envp);
	pid2 = fork();
	if (pid2 == -1)
		perror("fork");
	if (pid2 == 0)
		child2(fd, av, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

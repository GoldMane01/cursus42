/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:16:30 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:32 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cp1(int *link, char **arg)
{
	char	buffer[1025];
	int		bytes;
	int		fd;

	close(link[0]);
	dup2(link[1], STDOUT_FILENO);
	if (access(arg[0], R_OK) != 0)
	{
		perror("Could not access input file");
		exit(1);
	}
	fd = open(arg[0], O_RDONLY);
	bytes = read(fd, buffer, 1024);
	buffer[bytes] = '\0';
	write(STDOUT_FILENO, buffer, bytes);
	close(link[1]);
	exit(1);
}

void	first_cp2(int *link, char **arg, char *envp[])
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open("temp", O_RDWR | O_CREAT, 0666);
	if (access("temp", W_OK) != 0)
	{
		unlink("temp");
		perror("Temp file was not created properly");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(link[0]);
	if (execve(cmdname(arg[1], envp), cmdargs(arg), NULL) == -1)
	{
		perror("First command could not be executed");
		exit(1);
	}
}

void	second_cp1(int *link)
{
	char	buffer[1025];
	int		bytes;
	int		fd;

	close(link[0]);
	dup2(link[1], STDOUT_FILENO);
	if (access("temp", R_OK) != 0)
	{
		unlink("temp");
		perror("Could not access temp file");
		exit(1);
	}
	fd = open("temp", O_RDONLY);
	bytes = read(fd, buffer, 1024);
	buffer[1024] = '\0';
	write(STDOUT_FILENO, buffer, bytes);
	close(link[1]);
	exit(1);
}

void	second_cp2(int *link, char **arg, char *envp[])
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open(arg[0], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (access(arg[0], W_OK) != 0)
	{
		unlink("temp");
		perror("Could not write into temp file");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(link[0]);
	if (execve(cmdname(arg[1], envp), cmdargs(arg), NULL) == -1)
	{
		perror("Second command could not be executed");
		exit(1);
	}
}

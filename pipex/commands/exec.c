/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:07:40 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:07:41 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	read_temp(int link[])
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
	buffer[bytes] = '\0';
	write(STDOUT_FILENO, buffer, bytes);
	close(link[1]);
}

void	read_input(int link[], char *infile)
{
	char	buffer[1025];
	int		bytes;
	int		fd;

	close(link[0]);
	dup2(link[1], STDOUT_FILENO);
	if (access(infile, R_OK) != 0)
	{
		perror("Could not access input file");
		exit(1);
	}
	fd = open(infile, O_RDONLY);
	bytes = read(fd, buffer, 1024);
	buffer[bytes] = '\0';
	write(STDOUT_FILENO, buffer, bytes);
	close(link[1]);
}

void	read_file(char *infile, int cmdnum, int fd[])
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmdnum == 0)
			read_input(fd, infile);
		else
			read_temp(fd);
		exit(1);
	}
	waitpid(pid, NULL, 0);
}

void	execute_command(int fd[], char **cmds, int cmdn,  char *env[], char *out)
{
	int		pid;
	char	**split;

	pid = fork();
	if (pid == 0)
	{
		if (ft_strnstr(cmds[cmdn], "awk", 3))
			split = awk_split(cmds[cmdn]);
		else
			split = ft_split(cmds[cmdn], ' ');
		if (!last_command(cmds, cmdn))
			write_temp(fd, cmdname(cmds[cmdn], env), split);
		else
			write_output(fd, cmdname(cmds[cmdn], env), split, out);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

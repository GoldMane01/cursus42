/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:12:40 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:12:41 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	write_temp(int link[], char *path, char **arg)
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (access("temp", W_OK) != 0)
	{
		unlink("temp");
		perror("Temp file could not be accessed");
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(link[0]);
	if (execve(path, arg, NULL) == -1)
	{
		perror("Command could not be executed");
		exit(1);
	}
}

int	create_temp_file()
{
	int	fd;

	fd = open("temp", O_RDWR | O_CREAT, 0644);
	if (access("temp", W_OK) != 0 || access("temp", R_OK) != 0)
	{
		unlink("temp");
		perror("Temp file was not created properly");
		exit(1);
	}
	return (fd);
}

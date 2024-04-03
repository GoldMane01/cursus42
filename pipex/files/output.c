/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:07:16 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:07:17 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	write_output(int link[], char *path, char **arg, char *outfile)
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (access(outfile, W_OK) != 0)
	{
		perror("Output file could not be accessed");
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

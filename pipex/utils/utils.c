/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:27:01 by dramos-n          #+#    #+#             */
/*   Updated: 2024/05/27 17:27:03 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	argv_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**awk_split(char *command)
{
	char	**awk;

	awk = malloc(sizeof(char *) * 3);
	if (!awk)
		return (NULL);
	awk[2] = NULL;
	awk[0] = malloc(sizeof(char) * 4);
	if (!awk[0])
		return (NULL);
	awk[0] = "awk\0";
	command += 5;
	awk[1] = malloc(sizeof(char) * (ft_strlen(command) + 1));
	if (!awk[1])
		return (NULL);
	ft_strlcpy(awk[1], command, ft_strlen(command));
	return (awk);
}

int	last_command(char **commands, int cmdnum)
{
	int	i;

	i = 0;
	while (commands[i])
		i++;
	if (i == cmdnum + 1)
		return (1);
	return (0);
}

int	create_temp_file(void)
{
	int	fd;

	fd = open("temp", O_RDWR | O_CREAT, 0666);
	if (access("temp", W_OK) != 0 || access("temp", R_OK) != 0)
	{
		unlink("temp");
		perror("Temp file was not created properly");
		exit(1);
	}
	return (fd);
}

char	*cmdname(char *s, char *envp[])
{
	char	**allpaths;
	char	*path;
	char	*command;

	allpaths = find_paths(envp);
	*allpaths += 5;
	command = malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (!command)
		return (NULL);
	ft_strlcpy(command, "/", 2);
	ft_strlcat(command, s, ft_strlen(s) + ft_strlen(command) + 1);
	path = check_paths(allpaths, command);
	return (path);
}

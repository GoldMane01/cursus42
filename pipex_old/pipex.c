/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:16:47 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:48 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	second_command(char **arg, char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		perror("Pipe has failed to execute");
	pid1 = fork();
	if (pid1 == 0)
		second_cp1(fd);
	pid2 = fork();
	if (pid2 == 0)
		second_cp2(fd, arg, envp);
	close(fd[0]);
	close(fd[1]);
	return (pid2);
}

int	first_command(char **arg, char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		perror("Pipe has failed to execute");
	pid1 = fork();
	if (pid1 == 0)
		first_cp1(fd, arg);
	pid2 = fork();
	if (pid2 == 0)
		first_cp2(fd, arg, envp);
	close(fd[0]);
	close(fd[1]);
	return (pid2);
}

void	awk_parsing(int argc, char *argv[], char *envp[])
{
	argc = 0;

	int i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("-----------------------------------");
	i = 0;

}

int	main(int argc, char *argv[], char *envp[])
{
	char	**arg;
	int		pid1;
	int		pid2;

	if (find_awk(argv))
	{
		awk_parsing(argc, argv, envp);
		//return (0);
	}
	if (argc != 5)
	{
		perror("Number of arguments different than 4");
		exit(1);
	}
	arg = get_params(argv[1], argv[2]);
	pid1 = first_command(arg, envp);
	waitpid(pid1, NULL, 0);
	arg = get_params(argv[4], argv[3]);
	pid2 = second_command(arg, envp);
	waitpid(pid2, NULL, 0);
	unlink("temp");
	return (0);
}

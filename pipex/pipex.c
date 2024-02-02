#include "pipex.h"

int	second_command(char **arg)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		perror("Pipe has failed to execute");
	pid1 = fork();
	if (pid1 == 0)
		second_cp1(fd, arg);
	pid2 = fork();
	if (pid2 == 0)
		second_cp2(fd, arg);
	close(fd[0]);
	close(fd[1]);
	return (pid2);
}

int	first_command(char **arg)
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
		first_cp2(fd, arg);
	close(fd[0]);
	close(fd[1]);
	return (pid2);
}

int	main(int argc, char *argv[])
{
	char	**arg;
	int		pid1;
	int		pid2;

	if (argc != 5)
		return (0);
	arg = get_params(argv[1], argv[2]);
	pid1 = first_command(arg);
	waitpid(pid1, NULL, 0);
	arg = get_params(argv[4], argv[3]);
	pid2 = second_command(arg);
	waitpid(pid2, NULL, 0);
	unlink("temp");
	return (0);
}

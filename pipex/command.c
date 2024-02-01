#include "pipex.h"

void	first_cp1(int *link, char **arg)
{
	char	buffer[1025];
	int		bytes;
	int		fd;

	close(link[0]);
	dup2(link[1], STDOUT_FILENO);
	fd = open(arg[0], O_RDONLY);
	bytes = read(fd, buffer, 1024);
	write(STDOUT_FILENO, buffer, bytes);
	close(link[1]);
	exit(1);
}

void	first_cp2(int *link, char **arg)
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open("temp", O_RDWR | O_CREAT, 0666);
	if (access("temp", W_OK) != 0)
	{
		unlink("temp");
		perror("Could not access file");
	}
	dup2(fd, STDOUT_FILENO);
	close(link[0]);
	if (execve(cmdname(arg[1]), cmdargs(arg), NULL) == -1)
		perror("Command could not be executed");
}
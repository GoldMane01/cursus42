#include "../pipex.h"

void	write_output(int link[], char *path, char **arg, char *outfile)
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
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

void	write_temp(int link[], char *path, char **arg)
{
	int	fd;

	close(link[1]);
	dup2(link[0], STDIN_FILENO);
	fd = open("temp", O_RDWR | O_TRUNC, 0666);
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

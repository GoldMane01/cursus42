#include "../pipex.h"

void	read_temp(int link[])
{
	char	buffer[1025];
	int		bytes;
	int		fd;

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
}

void	read_input(int link[], char *infile)
{
	char	buffer[1025];
	int		bytes;
	int		fd;

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
}

void	read_file(char *infile, int input, int fd[])
{
	if (input == 1)
		read_input(fd, infile);
	else
		read_temp(fd);
}

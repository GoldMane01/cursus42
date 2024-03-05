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
	buffer[1024] = '\0';
	write(STDOUT_FILENO, buffer, bytes);
	close(link[1]);
	exit(1);
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
	exit(1);
}

void	execute_command(char **commands, int cmdnum, char *infile, char *envp[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		//if (cmdnum == 0)
			//read_input(fd, infile);
		//else
			//read_temp(fd);
		cmdname(commands[cmdnum], envp);
		if (!last_command(commands, cmdnum))
		{
			
			//printf("%s\n", cmdname(commands[cmdnum], envp));
			//write_temp(fd, cmdname(commands[cmdnum], envp), commands[cmdnum]);
		}
	}
	waitpid(pid, NULL, 0);
}
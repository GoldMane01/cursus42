#include "pipex.h"

void	second_file()
{
	int link[2];
	char *argvec[] = {"wc", "-l", NULL};
	int pid1;
	int pid2;
	char buffer[10];
	int bytes;
	int fd;

	pipe(link);

	pid1 = fork();
	if (pid1 == 0)
	{
		close(link[0]);
		dup2(link[1], STDOUT_FILENO);
		fd = open("output", O_RDONLY);
		//read(fd, buffer, 1024);
		while(read(fd, buffer, 10))
		{
			write(STDOUT_FILENO, buffer, bytes);
		}
		//buffer[1024] = '\0';
		
		close(link[1]);
		exit(1);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		close(link[1]);
		dup2(link[0], STDIN_FILENO);
		fd = open("final", O_RDWR | O_TRUNC);
		dup2(fd, STDOUT_FILENO);
		close(link[0]);
		execve("/bin/wc", argvec, NULL);
	}
}

void	first_file()
{
	int link[2];
	char *argvec[] = {"ping", "-c", "5", "google.com", NULL};
	int pid1;
	int pid2;
	char buffer[1025];
	int bytes;
	int fd;

	if (pipe(link) == -1)
		return ;

	pid1 = fork();
	if (pid1 == 0)
	{
		close(link[0]);
		dup2(link[1], STDOUT_FILENO);
		fd = open("filexd", O_RDONLY);
		bytes = read(fd, buffer, 1024);
		buffer[1024] = '\0';
		write(STDOUT_FILENO, buffer, bytes);
		close(link[1]);
		exit(1);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		close(link[1]);
		dup2(link[0], STDIN_FILENO);
		fd = open("output", O_RDWR);
		dup2(fd, STDOUT_FILENO);
		close(link[0]);
		execve("/bin/ping", argvec, NULL);
	}
}

int main(void)
{
	first_file();
	second_file();
	return 0;
}
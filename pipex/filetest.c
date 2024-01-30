#include "pipex.h"

int main(void)
{
	char buffer[1025];
	int bytes;
	int fd;
	int link[2];
	char *argvec[] = {"grep", "ennove", NULL};
	int pid1;
	int pid2;

	pipe(link);

	pid1 = fork();
	if (pid1 == 0)
	{
		close(link[0]);
		dup2(link[1], STDOUT_FILENO);
		close(link[0]);
		fd = open("filexd", O_RDONLY);
		bytes = read(fd, buffer, 1024);
		buffer[1024] = '\0';
		write(STDOUT_FILENO, buffer, bytes);
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		close(link[1]);
		dup2(link[0], STDIN_FILENO);
		close(link[0]);
		execve("/bin/grep", argvec, NULL);
	}
	close(link[0]);
	close(link[1]);
	return 0;
}
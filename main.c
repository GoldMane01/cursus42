#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int fd[2];
	if (pipe(fd) == -1) {
		return 1;
	}

	int pid1 = fork();
	if (pid1 < 0) {
		return 2;
	}

	if (pid1 == 0) {

		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);

		char *args[3];
		args[0] = "ls";
		args[1] = "-l";
		args[2] = NULL;
		execve("/usr/bin/ls", args, NULL);
	}

	int pid2 = fork();
	if (pid2 < 0) {
		return 3;
	}

	if (pid2 == 0) {

		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);

		char *args[3];
		args[0] = "awk";
		args[1] = "END {print NR}";
		args[2] = NULL;
		execve("/usr/bin/awk", args, NULL);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return 0;
}

/*

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
	command+=5;
	awk[1] = malloc(sizeof(char) * (ft_strlen(command) + 1));
	if (!awk[1])
		return (NULL);
	ft_strlcpy(awk[1], command, ft_strlen(command));
	return (awk);
}

*/
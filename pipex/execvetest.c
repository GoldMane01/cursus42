#include "pipex.h"

int	main(void)
{
	char	cmd[] = "/usr/bin/ls";
	char	*argvec[] = {"ls", "-l", "-h", NULL};
	//char	*envvec[] = {NULL};

	if (execve(cmd, argvec, NULL) == -1)
	{
		perror("could not execute execve");
	}
}
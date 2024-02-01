#include "pipex.h"

int	main(int argc, char *argv[])
{
	char	cmd[] = "/bin/grep";
	char	*argvec[] = {"grep", "ennove", NULL};
	char	*argvec2[] = {"cat", NULL};
	//char	*envvec[] = {NULL};

	if (execve(cmd, argvec, NULL) == -1)
	{
		perror("could not execute execve");
	}
	execve("/bin/cat", argvec, NULL);
}
#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**commands;
	int		cmdnum;
	int		tempfd;
	int		fd[2];
	int		pid;

	commands = get_commands(argv, argc);
	tempfd = create_temp_file();
	cmdnum = 0;
	while (commands[cmdnum])
	{
		if (pipe(fd) == -1)
			exit(1);
		pid = fork();
		if (pid == 0)
		{
			read_file(argv[1], cmdnum, fd);
			execute_command(fd, commands, cmdnum, envp, argv[argc - 1]);
			close(fd[0]);
			close(fd[1]);
		}
		cmdnum++;
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}
	unlink("temp");
	return (0);
}
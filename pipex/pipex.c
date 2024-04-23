#include "pipex.h"

void	execute_command(char **argv, char **envp, char *infile, int first_read)
{
	int		fd[2];
	int		pid;
	char	**split;
	char	*out;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == 0)
	{
		out = argv[argv_size(argv) - 1];
		read_file(infile, first_read, fd);
		if (ft_strnstr(*argv, "awk", 3))
			split = awk_split(*argv);
		else
			split = ft_split(*argv, ' ');
		if (argv_size(argv) > 2)
			write_temp(fd, cmdname(*argv, envp), split);
		else
			write_output(fd, cmdname(*argv, envp), split, out);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	//free(cmds[cmdn]);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*infile;
	int		first_read;

	if (argc < 5)
	{
		write(2, "Bad input\n", 10);
		return (1);
	}
	create_temp_file();
	infile = argv[1];
	argv += 2;
	first_read = 1;
	while (*argv)
	{
		if (argv_size(argv) > 1)
			execute_command(argv, envp, infile, first_read);
		first_read = 0;
		argv++;
	}
	unlink("temp");
	return (0);
}

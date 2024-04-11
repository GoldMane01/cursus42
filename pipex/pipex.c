#include "pipex.h"

void	execute_command(char **cmds, int cmdn, char **argv, char **envp)
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
		read_file(argv[1], cmdn, fd);
		if (ft_strnstr(cmds[cmdn], "awk", 3))
			split = awk_split(cmds[cmdn]);
		else
			split = ft_split(cmds[cmdn], ' ');
		if (!last_command(cmds, cmdn))
			write_temp(fd, cmdname(cmds[cmdn], envp), split);
		else
			write_output(fd, cmdname(cmds[cmdn], envp), split, out);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**cmds;
	int		cmdn;

	cmds = get_commands(argv, argc);
	create_temp_file();
	cmdn = 0;
	while (cmds[cmdn])
	{
		execute_command(cmds, cmdn, argv, envp);
		cmdn++;
	}
	unlink("temp");
	return (0);
}

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**commands;
	char	**paths;
	int		cmdnum;
	int		tempfd;

	commands = get_commands(argv, argc);
	tempfd = create_temp_file();
	paths = find_paths(envp);
	cmdnum = 0;
	while (commands[cmdnum])
	{
		execute_command(commands, cmdnum, argv[1]);
	}
	return (0);
}
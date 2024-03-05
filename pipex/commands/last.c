#include "../pipex.h"

int	last_command(char **commands, int cmdnum)
{
	int	i;

	i = 0;
	while (commands[i])
		i++;
	if (i == cmdnum)
		return (1);
	return (0);
}
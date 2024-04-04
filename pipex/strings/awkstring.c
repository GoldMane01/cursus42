#include "../pipex.h"

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

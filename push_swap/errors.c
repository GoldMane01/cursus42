#include "push_swap.h"

int	check_chars(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		s++;
	}
	return (1);
}

int	check_input(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 3)
		return(-1);
	while (argv[++i])
	{
		if (!check_chars(argv[i]))
			return (-1);
	}
	return (1);
}
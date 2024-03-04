#include "../pipex.h"

int	create_temp_file()
{
	int	fd;

	fd = open("temp", O_RDWR | O_CREAT, 0666);
	if (access("temp", W_OK) != 0 || access("temp", R_OK) != 0)
	{
		unlink("temp");
		perror("Temp file was not created properly");
		exit(1);
	}
	return (fd);
}
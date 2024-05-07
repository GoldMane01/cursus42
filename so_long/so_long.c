#include "so_long.h"

char	**read_map(char *path, int rows)
{
	char	**gnl;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	gnl = malloc(sizeof(char *) * rows);
	i = 0;
	while (rows-- > 0)
	{
		gnl[i] = get_next_line(fd);
		i++;
	}
	gnl[i] = NULL;
	return (gnl);
}

int	get_rows(char *path)
{
	int	fd;
	int	rows;
	char	*gnl;


	fd = open(path, O_RDONLY);
	rows = 0;
	while(get_next_line(fd))
		rows++;
	return (rows);
}

int	check_extra(char **map, int c)
{
	int	i;
	int	j;
	int	extra_count;

	i = 0;
	extra_count = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == c)
				extra_count++;
			j++;
		}
		i++;
	}
	if (extra_count == 0 || extra_count > 1)
		return (0);
	return (1);
}

int	check_missing(char **map, int c)
{
	int	i;
	int	parameter_count;

	i = 0;
	parameter_count = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], c))
			parameter_count++;
		i++;
	}
	if (parameter_count == 0)
		return (0);
	return (1);
}

int	check_parameters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;


		printf("%s\n", map[i]);

		/*while (map[i][j])
		{
			//if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
			//	&& map[i][j] != 'C' && map[i][j] != 'E')
			//	return (0);
			j++;
		}*/
		i++;
	}
	return (1);
}

int	map_check(char **map, int cols)
{
	int	i;

	while(map[i])
	{
		//if (map[i][ft_strlen(map[i]) - 1] == '\n')
		//	map[i][ft_strlen(map[i]) - 2] = '\0';
		//if (ft_strlen(map[i]) < 4 || ft_strlen(map[i]) != cols)
		//	return (0);
		//i++;
	}
	if (!check_extra(map, 'P'))
		return (0);
	if (!check_missing(map, 'C'))
		return (0);
	if (!check_missing(map, 'P'))
		return (0);
	if (!check_missing(map, 'E'))
		return (0);
	if (!check_parameters(map))
		return (0);
	return (1);
}

int	extension_check(char *path)
{
	if (ft_strlen(path) < 5)
		return (0);
	path += ft_strlen(path) - 4;
	if (ft_strncmp(path, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		rows;

	if (!argv[1] || !extension_check(argv[1]))
		return (1);
	rows = get_rows(argv[1]);
	map = read_map(argv[1], rows);
	if (!map_check(map, ft_strlen(map[0]) - 2))
		return (1);
	return (0);
}

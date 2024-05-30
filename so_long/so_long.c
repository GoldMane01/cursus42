#include "so_long.h"

char	**read_map(char *path, int rows)
{
	char	**gnl;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	gnl = malloc(sizeof(char *) * (rows + 1));
	i = 0;
	while (rows-- > 0)
	{
		gnl[i] = get_next_line(fd);
		i++;
	}
	gnl[i] = NULL;
	return (gnl);
}

void	free_map(char **map)
{
	int	i = 0;

	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	get_rows(char *path)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(path, O_RDONLY);
	rows = 0;
	line = get_next_line(fd);
	while(line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		while (map[i][j])
		{
			if (!ft_strchr("10PCE", map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_size(char **map, int cols)
{
	int	i;

	i = 0;
	while(map[i])
	{
		
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		if (ft_strlen(map[i]) < 4 || ft_strlen(map[i]) != cols)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map, int rows, int cols)
{
	int	j;
	int	i;

	i = 0;
	if (map[i][ft_strlen(map[i]) - 1] == '\n')
		map[i][ft_strlen(map[i]) - 1] = '\0';
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != map[rows - 1][j])
			return (0);
		j++;
	}
	while(map[i])
	{
		if (map[i][0] != map[i][cols - 1])
			return (0);
		i++;
	}
	return (1);
}

void	recursive_flood(char **map, int x, int y)
{
	if (map[y][x] && (map[y][x] == '0' || map[y][x] == 'P'
		|| map[y][x] == 'C' || map[y][x] == 'E'))
	{
		map[y][x] = 'X';
		recursive_flood(map, x - 1, y);
		recursive_flood(map, x + 1, y);
		recursive_flood(map, x, y - 1);
		recursive_flood(map, x, y + 1);
	}
}

int	flood_fill(char **map)
{
	int	row;
	int	col;
	int	check;

	row = 0;
	col = 0;
	check = 0;
	while (!ft_strchr(map[row], 'P'))
		row++;
	while (map[row][col] && map[row][col] != 'P')
		col++;
	recursive_flood(map, col, row);
	if (!check_missing(map, 'P') && !check_missing(map, 'E')
		&& !check_missing(map, 'C'))
		check = 1;
	free_map(map);
	return (check);
}

char	**map_copy(char **map, int rows, int cols)
{
	char	**mapCopy;
	int		i;
	int		j;

	mapCopy = malloc(sizeof(char *) * (rows + 1));
	if (!mapCopy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		mapCopy[i] = malloc(sizeof(char) * (cols + 2));
		j = 0;
		while (map[i][j])
		{
			mapCopy[i][j] = map[i][j];
			j++;
		}
		mapCopy[i][j] = '\0';
		i++;
	}
	mapCopy[i] = NULL;
	return (mapCopy);
}

int	map_check(char **map, int cols, int rows)
{
	if (!check_size(map, cols))
		return (0);
	if (!check_extra(map, 'P'))
		return (0);
	if (!check_extra(map, 'E'))
		return (0);
	if (!check_missing(map, 'C'))
		return (0);
	if (!check_missing(map, 'P'))
		return (0);
	if (!check_missing(map, 'E'))
		return (0);
	if (!check_parameters(map))
		return (0);
	if (!check_walls(map, rows, cols))
		return (0);
	if (!flood_fill(map_copy(map, rows, cols)))
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
	mlx_t	*game;

	if (!argv[1] || !extension_check(argv[1]))
		return (1);
	rows = get_rows(argv[1]);
	map = read_map(argv[1], rows);
	if (!map)
		return (1);
	if (!map_check(map, ft_strlen(map[0]) - 1, rows))
		return (1);
	
	game = mlx_init((ft_strlen(map[0]) - 1) * TILE, rows * TILE, 
			"42Balls", false);

	mlx_loop(game);


	free_map(map);
	return (0);
}

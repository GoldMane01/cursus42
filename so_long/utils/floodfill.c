#include "../so_long.h"

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

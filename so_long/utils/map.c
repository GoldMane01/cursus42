/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:34:26 by dramos-n          #+#    #+#             */
/*   Updated: 2024/06/12 16:34:27 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(char *path, int rows, t_game *game)
{
	char	**gnl;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error(game, "Map could not be opened");
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

int	get_rows(char *path)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(path, O_RDONLY);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (rows);
}

char	**map_copy(char **map, int rows, int cols)
{
	char	**map_copy;
	int		i;
	int		j;

	map_copy = malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = malloc(sizeof(char) * (cols + 2));
		j = 0;
		while (map[i][j])
		{
			map_copy[i][j] = map[i][j];
			j++;
		}
		map_copy[i][j] = '\0';
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

int	extension_check(char *path, t_game *game)
{
	if (ft_strlen(path) < 5)
		print_error(game, "Map extension isn't right");
	path += ft_strlen(path) - 4;
	if (ft_strncmp(path, ".ber", 4) != 0)
		print_error(game, "Map extension isn't right");
	return (1);
}

int	map_check(char **map, int cols, int rows, t_game *game)
{
	if (!check_size(map, cols))
		print_error(game, "Map isn't a rectangle");
	if (!check_extra(map, 'P'))
		print_error(game, "Extra player");
	if (!check_extra(map, 'E'))
		print_error(game, "Extra exit");
	if (!check_missing(map, 'C'))
		print_error(game, "No items");
	if (!check_missing(map, 'P'))
		print_error(game, "No player");
	if (!check_missing(map, 'E'))
		print_error(game, "No exit");
	if (!check_parameters(map))
		print_error(game, "Unknown parameters");
	if (!check_walls(map, rows, cols))
		print_error(game, "Missing wall");
	if (!flood_fill(map_copy(map, rows, cols)))
		print_error(game, "Enclosed player");
	return (1);
}

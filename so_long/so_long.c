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
	int	i;

	i = 0;
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
	while (line)
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
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
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
	while (map[i])
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
	while (map[i])
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

void	get_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->ground = mlx_load_png("./assets/ground.png");
	game->textures->wall = mlx_load_png("./assets/wall.png");
	game->textures->player = mlx_load_png("./assets/player.png");
	game->textures->exit_closed = mlx_load_png("./assets/exit_closed.png");
	game->textures->item = mlx_load_png("./assets/item.png");
}

void	get_images(t_game *game)
{
	game->images = ft_calloc(1, sizeof(t_images));
	game->images->ground = mlx_texture_to_image(game->mlx,
			game->textures->ground);
	game->images->wall = mlx_texture_to_image(game->mlx,
			game->textures->wall);
	game->images->player = mlx_texture_to_image(game->mlx,
			game->textures->player);
	game->images->item = mlx_texture_to_image(game->mlx,
			game->textures->item);
	game->images->exit_closed = mlx_texture_to_image(game->mlx,
			game->textures->exit_closed);
	mlx_delete_texture(game->textures->ground);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->exit_closed);
	mlx_delete_texture(game->textures->item);
}

void	place_ground(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, game->images->ground,
				x * TILE, y * TILE);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->images->wall,
					x * TILE, y * TILE);
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->images->exit_closed,
					x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

void	place_assets(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->images->player,
					x * TILE, y * TILE);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->images->item,
					x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

void	key_w(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->images->player->instances[0];
		game->player_y--;

	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	param = (t_game *) param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		key_w(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		key_a(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		key_s(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		key_d(param);
}

void	init_game(t_game *game, char *name, int rows)
{
	int	x;
	int	y;

	game->moves = 0;
	game->map = read_map(name, rows);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	place_textures(t_game *game)
{
	get_textures(game);
	get_images(game);
	place_ground(game);
	place_assets(game);
}

void	start_game(t_game *game, int rows)
{
	game->mlx = mlx_init((ft_strlen(game->map[0]) - 1) * TILE, rows * TILE,
			"So Long", false);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	int		rows;
	t_game	*game;

	if (!argv[1] || !extension_check(argv[1]))
		return (1);
	rows = get_rows(argv[1]);
	init_game(game, argv[1], rows);
	place_textures(game);
	if (!(game->map))
		return (1);
	if (!map_check(game->map, ft_strlen(game->map[0]) - 1, rows))
		return (1);
	start_game(game, rows);
	free_map(game->map);
	return (0);
}

#include "so_long.h"

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

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->images)
		free(game->images);
	if (game)
		free(game);
}

void	print_error(t_game *game, char *message)
{
	if (game)
		free_game(game);
	write(1, "Error: ", 7);
	write(1, message, ft_strlen(message));
	exit(1);
}

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

void	get_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->ground = mlx_load_png("./assets/ground.png");
	game->textures->wall = mlx_load_png("./assets/wall.png");
	game->textures->player = mlx_load_png("./assets/player.png");
	game->textures->exit_closed = mlx_load_png("./assets/exit_closed.png");
	game->textures->exit_open = mlx_load_png("./assets/exit_open.png");
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
	game->images->exit_open = mlx_texture_to_image(game->mlx,
			game->textures->exit_open);
	mlx_delete_texture(game->textures->ground);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->exit_closed);
	mlx_delete_texture(game->textures->exit_open);
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
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->images->item,
					x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->images->player,
		game->player_x * TILE, game->player_y * TILE);
}

void	collect_item(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->items_collected++;
	mlx_image_to_window(game->mlx, game->images->ground,
		game->player_x * TILE, game->player_y * TILE);
	mlx_delete_image(game->mlx, game->images->player);
	game->textures->player = mlx_load_png("./assets/player.png");
	game->images->player = mlx_texture_to_image(game->mlx,
			game->textures->player);
	mlx_image_to_window(game->mlx, game->images->player,
		game->player_x * TILE, game->player_y * TILE);
}

void	exit_game(t_game *game)
{
	mlx_terminate(game->mlx);
	free_game(game);
	exit(0);
}

void	check_exit(t_game *game)
{
	if (game->items_collected == game->item_count)
	{
		mlx_terminate(game->mlx);
		free_game(game);
		exit(0);
	}
}

void	open_exit(t_game *game)
{
	mlx_image_to_window(game->mlx, game->images->ground,
		game->exit_x * TILE, game->exit_y * TILE);
	mlx_image_to_window(game->mlx, game->images->exit_open,
		game->exit_x * TILE, game->exit_y * TILE);
}

void	key_w(t_game *game)
{
	char	*move;

	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->images->player->instances[0].y -= TILE;
		game->player_y--;
		game->moves++;
		move = ft_itoa(game->moves);
		write(1, "Moves: ", 7);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->items_collected == game->item_count)
			open_exit(game);
		if (game->map[game->player_y][game->player_x] == 'E')
			check_exit(game);
	}
}

void	key_a(t_game *game)
{
	char	*move;

	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->images->player->instances[0].x -= TILE;
		game->player_x--;
		game->moves++;
		move = ft_itoa(game->moves);
		write(1, "Moves: ", 7);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->items_collected == game->item_count)
			open_exit(game);
		if (game->map[game->player_y][game->player_x] == 'E')
			check_exit(game);
	}
}

void	key_s(t_game *game)
{
	char	*move;

	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->images->player->instances[0].y += TILE;
		game->player_y++;
		game->moves++;
		move = ft_itoa(game->moves);
		write(1, "Moves: ", 7);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->items_collected == game->item_count)
			open_exit(game);
		if (game->map[game->player_y][game->player_x] == 'E')
			check_exit(game);
	}
}

void	key_d(t_game *game)
{
	char	*move;

	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->images->player->instances[0].x += TILE;
		game->player_x++;
		game->moves++;
		move = ft_itoa(game->moves);
		write(1, "Moves: ", 7);
		write(1, move, ft_strlen(move));
		write(1, "\n", 1);
		free(move);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->map[game->player_y][game->player_x] == 'C')
			collect_item(game);
		if (game->items_collected == game->item_count)
			open_exit(game);
		if (game->map[game->player_y][game->player_x] == 'E')
			check_exit(game);
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
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		&& keydata.action == MLX_PRESS)
		exit_game(param);
}

int	count_items(t_game *game)
{
	int	items;
	int	y;
	int	x;

	items = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				items++;
			x++;
		}
		y++;
	}
	return (items);
}

void	init_game(t_game *game, char *name, int rows)
{
	int	x;
	int	y;

	game->map = read_map(name, rows, game);
	game->item_count = count_items(game);
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
	game->moves = 0;
	game->items_collected = 0;
	game->mlx = mlx_init(ft_strlen(game->map[0]) * TILE, rows * TILE,
			"So Long", false);
	place_textures(game);
	mlx_key_hook(game->mlx, &my_keyhook, game);
	mlx_loop(game->mlx);
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

int	main(int argc, char **argv)
{
	int		rows;
	t_game	*game;

	if (argc > 2 || !argv[1])
		return (1);
	rows = get_rows(argv[1]);
	game = NULL;
	game = malloc(sizeof(t_game) * 1);
	init_game(game, argv[1], rows);
	if (!(game->map))
		return (1);
	extension_check(argv[1], game);
	map_check(game->map, ft_strlen(game->map[0]) - 1, rows, game);
	start_game(game, rows);
	free_game(game);
	return (0);
}

#include "../so_long.h"

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

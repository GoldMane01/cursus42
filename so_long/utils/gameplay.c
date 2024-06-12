/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:34:17 by dramos-n          #+#    #+#             */
/*   Updated: 2024/06/12 16:34:19 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	mlx_delete_texture(game->textures->player);
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

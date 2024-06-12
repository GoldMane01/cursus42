/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:33:46 by dramos-n          #+#    #+#             */
/*   Updated: 2024/06/12 16:33:47 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

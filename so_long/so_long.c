/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:33:35 by dramos-n          #+#    #+#             */
/*   Updated: 2024/06/12 16:33:37 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	int		rows;
	t_game	*game;

	if (argc > 2 || !argv[1])
		return (1);
	rows = get_rows(argv[1]);
	game = malloc(sizeof(t_game));
	init_game(game, argv[1], rows);
	if (!(game->map))
		return (1);
	extension_check(argv[1], game);
	map_check(game->map, ft_strlen(game->map[0]) - 1, rows, game);
	start_game(game, rows);
	free_game(game);
	return (0);
}

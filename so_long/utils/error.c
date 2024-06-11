#include "../so_long.h"

void	print_error(t_game *game, char *message)
{
	if (game)
		free_game(game);
	write(1, "Error: ", 7);
	write(1, message, ft_strlen(message));
	exit(1);
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

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	if (game->images)
		free(game->images);
	if (game)
		free(game);
}

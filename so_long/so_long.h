#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024
# define TILE 64

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

typedef struct s_textures
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*item;
	mlx_texture_t	*exit_closed;
	mlx_texture_t	*exit_open;
}					t_textures;

typedef struct s_images
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*item;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
}				t_images;

typedef struct s_game
{
	mlx_t		*mlx;
	t_images	*images;
	t_textures	*textures;
	char		**map;
	int			item_count;
	int			items_collected;
	int			moves;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
}				t_game;

//GNL
char	*get_next_line(int fd);
void	ft_lstadd(t_list **list, char *buffer);
int		find_nl(t_list *node);
int		len_nl(t_list *list);
void	free_all(t_list **list, t_list *clean_node, char *buffer);
t_list	*ft_lstlast(t_list *lst);

//LIB
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);

void	get_textures(t_game *game);
void	get_images(t_game *game);
void	place_ground(t_game *game);
void	place_assets(t_game *game);

char	**read_map(char *path, int rows, t_game *game);
int		get_rows(char *path);
char	**map_copy(char **map, int rows, int cols);
int		extension_check(char *path, t_game *game);
int		map_check(char **map, int cols, int rows, t_game *game);

int		flood_fill(char **map);
void	recursive_flood(char **map, int x, int y);

void	key_w(t_game *game);
void	key_a(t_game *game);
void	key_s(t_game *game);
void	key_d(t_game *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);

void	print_error(t_game *game, char *message);
void	free_map(char **map);
void	free_game(t_game *game);

int		check_extra(char **map, int c);
int		check_missing(char **map, int c);
int		check_parameters(char **map);
int		check_size(char **map, int cols);
int		check_walls(char **map, int rows, int cols);

void	collect_item(t_game *game);
void	exit_game(t_game *game);
void	check_exit(t_game *game);
void	open_exit(t_game *game);
int		count_items(t_game *game);

#endif
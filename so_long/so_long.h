#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1024

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

typedef struct s_map
{
	mlx_t	*mlx;
}				t_map;

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

#endif
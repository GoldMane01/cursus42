#include "../so_long.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:13:22 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:23 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_commands(char **commands)
{
	int	i;

	i = 0;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}

char	*get_argv(char *arg)
{
	char	*command;
	int		i;

	command = malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (!command)
		return (NULL);
	i = 0;
	while (arg[i])
	{
		command[i] = arg[i];
		i++;
	}
	command[i] = '\0';
	return (command);
}

char	**get_commands(char *argv[], int argc)
{
	char	**commands;
	int		i;

	commands = malloc(sizeof(char *) * (argc - 3) + 1);
	if (!commands)
		return (NULL);
	i = 0;
	while (i < (argc - 3))
	{
		commands[i] = get_argv(argv[i + 2]);
		commands[i] = argv[i + 2];
		if (!commands[i])
		{
			free_commands(commands);
			return (NULL);
		}
		i++;
	}
	commands[i] = NULL;
	return (commands);
}



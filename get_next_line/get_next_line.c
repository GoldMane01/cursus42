/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:01:01 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/19 14:01:02 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Removes all the content from the list that isn't needed anymore
void	clean_list(t_list **list)
{
	t_list	*last;
	t_list	*node;
	char	*buffer;
	int		i;
	int		j;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	node = malloc(sizeof(t_list));
	if (!buffer || !node)
		return ;
	last = ft_lstlast(*list);
	i = 0;
	while (last->str[i] && last->str[i] != '\n')
		i++;
	j = 0;
	while (last->str[i] != '\0' && last->str[++i])
		buffer[j++] = last->str[i];
	buffer[j] = '\0';
	node->str = buffer;
	node->next = NULL;
	free_all(list, node, buffer);
}

//Copies the resulting line from the list into a string.
void	copy_line(t_list *list, char *str)
{
	int	i;
	int	j;

	if (!list)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				str[j] = '\n';
				str[j + 1] = '\0';
				return ;
			}
			str[j++] = list->str[i++];
		}
		list = list->next;
	}
	str[j] = '\0';
}

//Deletes all elementes from the list and frees it.
void	delete_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
}

//Reads from the file until it finds a \n or the file ends
void	newlst(t_list **list, int fd)
{
	char	*buffer;
	int		bytes;

	while (!find_nl(*list))
	{
		buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			//If the read function fails, the entire list is deleted
			if (bytes == -1)
				delete_list(list);
			free(buffer);
			return ;
		}
		buffer[bytes] = '\0';
		ft_lstadd(list, buffer);
	}
}

//Replicates the get_next_line function
char	*get_next_line(int fd)
{
	//The chars will be stored in a static list
	static t_list	*list = NULL;
	char			*line;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newlst(&list, fd);
	if (!list)
		return (NULL);
	str = malloc(sizeof(char) * (len_nl(list) + 1));
	if (!str)
		return (NULL);
	copy_line(list, str);
	line = str;
	clean_list(&list);
	return (line);
}

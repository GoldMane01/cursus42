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

char	*get_line(t_list *list)
{
	int		len;
	char	*str;

	if (!list)
		return (NULL);
	
}

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
			free(buffer);
			return ;
		}
		buf[bytes] = '\0';
		ft_lstadd(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	newlst(&list, fd);
	if (!list)
		return (NULL);
	line = get_line(list);
}

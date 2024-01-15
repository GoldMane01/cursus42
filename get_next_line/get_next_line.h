/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:01:08 by dramos-n          #+#    #+#             */
/*   Updated: 2023/12/19 14:01:09 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	ft_lstadd(t_list **list, char *buffer);
int		find_nl(t_list *node);
int		len_nl(t_list *list);
void	free_all(t_list **list, t_list *clean_node, char *buffer);
t_list	*ft_lstlast(t_list *lst);

#endif

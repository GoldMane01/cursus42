/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:41:56 by dramos-n          #+#    #+#             */
/*   Updated: 2024/03/13 16:41:57 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				pos;
	struct s_list	*next;
}					t_list;

typedef struct gnl_list
{
	char			*str;
	struct gnl_list	*next;
}					t_gnl;

char		*get_next_line(int fd);
void		ft_lstadd_gnl(t_gnl **list, char *buffer);
int			find_nl(t_gnl *node);
int			len_nl(t_gnl *list);
void		free_all(t_gnl **list, t_gnl *clean_node, char *buffer);
t_gnl		*ft_lstlast_gnl(t_gnl *lst);
t_list		*ft_lstnew(int number, int position);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
int			ft_atoi(const char *str);
int			check_input(char **nums);
void		op_swap(t_list **head);
void		op_push(t_list **pull, t_list **push);
void		op_rev_rotate(t_list **head);
void		op_rotate(t_list **head);
void		position(t_list **stka);
void		turn_binary(t_list **stka);
void		iter_digit(t_list **stka, t_list **stkb, int power);
int			sorted(t_list **stk);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		**parse_input(char *argv[], int argc);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, int start, int len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);

#endif

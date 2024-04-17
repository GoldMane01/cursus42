/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-n <dramos-n@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:27:03 by dramos-n          #+#    #+#             */
/*   Updated: 2024/02/12 15:27:04 by dramos-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;


//Lib
t_stack	*ft_lstnew(int number);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

//Errors
int		syntax_check(char *str);
int		repeats_check(t_stack *a, int n);

//Free
void	free_all(t_stack **a, char **argv, bool argc);
void	free_argv(char **argv);
void	free_stack(t_stack **stack);

//Init
void	init_stack(t_stack **a, char **argv, bool argc);

//Commands
void	push(t_stack **pull, t_stack **push);
void	pa(t_stack **a, t_stack **b, int show);
void	pb(t_stack **a, t_stack **b, int show);
void	swap(t_stack **head);
void	sa(t_stack **a, int show);
void	sb(t_stack **b, int show);
void	ss(t_stack **a, t_stack **b, int show);
void	rotate(t_stack **head);
void	ra(t_stack **a, int show);
void	rb(t_stack **b, int show);
void	rr(t_stack **a, t_stack **b, int show);
void	rev_rotate(t_stack **head);
void	rra(t_stack **a, int show);
void	rrb(t_stack **b, int show);
void	rrr(t_stack **a, t_stack **b, int show);

//Sort
void	tiny_sort(t_stack **a);
void	five_sort(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);

//Utils
t_stack	*find_highest(t_stack *a);
t_stack	*find_smallest(t_stack *a);
t_stack	*find_cheapest(t_stack *stk);
int		sorted(t_stack **stk);
void	finish_rotation(t_stack **stk, t_stack *top, char stk_c);

//Setters
void	set_targets(t_stack *a, t_stack *b);
void	set_positions(t_stack *stk);
void	set_prices(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	set_all(t_stack *a, t_stack *b);

//Bonus
char	*get_next_line(int fd);
int		find_nl(t_list *node);
int		len_nl(t_list *list);
void	free_gnl(t_list **list, t_list *clean_node, char *buffer);
t_list	*ft_lstlast_gnl(t_list *lst);
void	ft_lstadd(t_list **list, char *buffer);

#endif

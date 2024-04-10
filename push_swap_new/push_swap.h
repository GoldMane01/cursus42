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

//Errors
int		syntax_check(char *str);
int		repeats_check(t_stack *a, int n);

//Free
void	free_all(t_stack **a, char **argv, bool argc);
void	free_argv(char **argv);

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

#endif

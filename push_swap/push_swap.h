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

typedef struct s_list
{
	int				num;
	int				pos;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int number);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		check_input(char **nums);
void	op_ss(t_list **stka, t_list **stkb);
void	op_rr(t_list **stka, t_list **stkb);
void	op_rrr(t_list **stka, t_list **stkb);
void	op_swap(t_list **head, int c, int prnt);
void	op_push(t_list **pull, t_list **push, int c, int prnt);
void	op_rev_rotate(t_list **head, int c, int prnt);
void	op_rotate(t_list **head, int c, int prnt);
void	position(t_list **stka);
void	turn_binary(t_list **stka);
void	iter_digit(t_list **stka, t_list **stkb, int power);
int		sorted(t_list **stk);
void	push_all(t_list **stka, t_list **stkb);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	sort_two(t_list **stk);
void	sort_three(t_list **stk);
void	radix_sort(t_list **stka, t_list **stkb);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	**parse_input(char *argv[], int argc);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
void	set_positions(t_list **stk);
void	set_target(t_list *stka, t_list *stkb);
void	push_swap(t_list **stka, t_list **stkb);
t_list	*find_smallest(t_list *stk);
void	set_price(t_list *stka, t_list *stkb);
void	set_cheapest(t_list *stkb);
void	refresh_nodes(t_list *stka, t_list *stkb);
void	move_nodes(t_list **stka, t_list **stkb);

#endif

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				pos;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int number, int position);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

int		ft_atoi(const char *str);

int		check_input(int argc, char *argv[]);

void	op_ss(t_list **stka, t_list **stkb);
void	op_rr(t_list **stka, t_list **stkb);
void	op_rrr(t_list **stka, t_list **stkb);

void	op_swap(t_list **head, int c);
void	op_push(t_list **pull, t_list **push, int c);
void	op_rev_rotate(t_list **head, int c);
void	op_rotate(t_list **head, int c);

void	position(t_list **stka);

void	turn_binary(t_list **stka);

#endif
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_lst
{
	int				numb;
	int				index;
	int				up;
	int				move;
	int				sum;
	struct s_lst	*next;
}					t_lst;

t_lst	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast_ps(t_lst *lst);
void	ft_lstadd_front_ps(t_lst **lst, t_lst *new);
int		ft_find_int_doubles(t_lst **stack_a);
int		ft_lstsize(t_lst *lst);
int		ft_parser(int ac, char **av, t_lst **stack_a);
int		ft_check_order(t_lst **stack_a);
void	ft_sa(t_lst **stack_a, int write_flag);
void	ft_sb(t_lst **stack_b, int write_flag);
void	ft_pa(t_lst **stack_b, t_lst **stack_a, int write_flag);
void	ft_pb(t_lst **stack_b, t_lst **stack_a, int write_flag);
void	ft_ra(t_lst **stack_a, int write_flag);
void	ft_rb(t_lst **stack_b, int write_flag);
void	ft_rr(t_lst **stack_a, t_lst **stack_b, int write_flag);
void	ft_rra(t_lst **stack_a, int write_flag);
void	ft_rrb(t_lst **stack_b, int write_flag);
void	ft_rrr(t_lst **stack_a, t_lst **stack_b, int write_flag);
void	ft_print_result(t_lst **stack_a);

#endif
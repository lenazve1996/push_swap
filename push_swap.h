#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_lst
{
	int				numb;
	struct s_lst	*next;
}					t_lst;

t_lst	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_lst **lst, t_lst *new);
t_lst	*ft_lstlast_ps(t_lst *lst);
void	ft_lstadd_front_ps(t_lst **lst, t_lst *new);
int		ft_find_int_doubles(t_lst **stack_a);
int		ft_parser(int ac, char **av);
int		ft_fill_stack_a(char *str, t_lst **stack_a);
#endif
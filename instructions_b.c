#include "push_swap.h"

void	ft_sb(t_lst **stack_b, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *new_head;

	tmp_elem = *stack_b;
	new_head = tmp_elem->next;
	tmp_elem->next = new_head->next;
	new_head->next = tmp_elem;
	*stack_b = new_head;
	if (write_flag)
		write(1, "sb\n", 3);
}

//void	ft_ss(t_lst **stack_b, t_lst **stack_a)
//{	
//	ft_sa(stack_a, 0);
//	ft_sb(stack_b, 0);
//	write(1, "ss\n", 3);
//}

void	ft_pb(t_lst **stack_b, t_lst **stack_a, int write_flag)
{
	t_lst *tmp_elem;

	if (stack_b != NULL)
	{
		tmp_elem = *stack_a;
		*stack_a = tmp_elem->next;
		ft_lstadd_front_ps(stack_b, tmp_elem);
	}
	if (write_flag)
		write(1, "pb\n", 3);
}

void	ft_rb(t_lst **stack_b, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *last_elem;

	if ((*stack_b) != NULL && (*stack_b)
	->next != NULL)
	{
		tmp_elem = *stack_b;
		*stack_b = tmp_elem->next;
		tmp_elem->next = NULL;
		last_elem = ft_lstlast_ps(*stack_b);
		last_elem->next = tmp_elem;
	}
	if (write_flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (write_flag)
		write(1, "rr\n", 3);
}

void	ft_rrb(t_lst **stack_b, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *last_elem;

	last_elem = ft_lstlast_ps(*stack_b);
	tmp_elem = *stack_b;
	while (tmp_elem->next->next != NULL)
		tmp_elem = tmp_elem->next;
	tmp_elem->next = NULL;
	ft_lstadd_front_ps(stack_b, last_elem);
	if (write_flag)
		write(1, "rrb\n", 4);
}
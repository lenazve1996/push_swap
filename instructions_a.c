/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:31:40 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/17 17:05:43 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_lst **stack_a, int write_flag)
{
	t_lst	*tmp_elem;
	t_lst	*new_head;

	tmp_elem = *stack_a;
	new_head = tmp_elem->next;
	tmp_elem->next = new_head->next;
	new_head->next = tmp_elem;
	*stack_a = new_head;
	if (write_flag)
		write(1, "sa\n", 3);
}

void	ft_pa(t_lst **stack_b, t_lst **stack_a, int write_flag)
{
	t_lst	*tmp_elem;

	if (stack_b != NULL && *stack_b != NULL)
	{
		tmp_elem = *stack_b;
		*stack_b = tmp_elem->next;
		ft_lstadd_front_ps(stack_a, tmp_elem);
	}
	if (write_flag)
		write(1, "pa\n", 3);
}

void	ft_ra(t_lst **stack_a, int write_flag)
{
	t_lst	*tmp_elem;
	t_lst	*last_elem;

	tmp_elem = *stack_a;
	*stack_a = tmp_elem->next;
	last_elem = ft_lstlast_ps(*stack_a);
	last_elem->next = tmp_elem;
	tmp_elem->next = NULL;
	if (write_flag)
		write(1, "ra\n", 3);
}

void	ft_rra(t_lst **stack_a, int write_flag)
{
	t_lst	*tmp_elem;
	t_lst	*last_elem;

	last_elem = ft_lstlast_ps(*stack_a);
	tmp_elem = *stack_a;
	while (tmp_elem->next->next != NULL)
		tmp_elem = tmp_elem->next;
	tmp_elem->next = NULL;
	ft_lstadd_front_ps(stack_a, last_elem);
	if (write_flag)
		write(1, "rra\n", 4);
}

void	ft_rrr(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (write_flag)
		write(1, "rrr\n", 4);
}

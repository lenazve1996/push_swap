/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:42:45 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 16:17:25 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_process_two_numbs(t_lst **stack_a)
{
	t_lst	*tmp_elem;

	tmp_elem = *stack_a;
	if (tmp_elem->numb > tmp_elem->next->numb)
		ft_sa(stack_a, 1);
	return (0);
}

int	ft_process_three_numbs(t_lst **stack_a)
{
	int	a;	
	int	b;	
	int	c;

	a = (*stack_a)->numb;
	b = (*stack_a)->next->numb;
	c = (*stack_a)->next->next->numb;
	if (a < b && a < c && b > c)
	{
		ft_rra(stack_a, 1);
		ft_sa(stack_a, 1);
		return (0);
	}
	else if (a > b && b < c && a < c)
		ft_sa(stack_a, 1);
	else if (a < b && a > c && b > c)
		ft_rra(stack_a, 1);
	else if (a > b && a > c && b < c)
		ft_ra(stack_a, 1);
	else if (a > b & a > c && b > c)
	{
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	return (0);
}

int	ft_process_four_numbs(t_lst **stack_a)
{
	t_lst	*min;
	t_lst	*stack_b;

	stack_b = NULL;
	ft_define_indexes(stack_a);
	min = ft_find_numb(stack_a, 0);
	while ((*stack_a)->index != 0)
		ft_ra(stack_a, 1);
	ft_pb(&stack_b, stack_a, 1);
	ft_process_three_numbs(stack_a);
	ft_pa(&stack_b, stack_a, 1);
	return (0);
}

int	ft_process_five_numbs(t_lst **stack_a)
{
	t_lst	*min;
	t_lst	*stack_b;

	stack_b = NULL;
	ft_define_indexes(stack_a);
	min = ft_find_numb(stack_a, 0);
	if (min->next == NULL)
		ft_rra(stack_a, 1);
	else
	{
		while ((*stack_a)->index != 0)
			ft_ra(stack_a, 1);
	}
	ft_pb(&stack_b, stack_a, 1);
	min = ft_find_numb(stack_a, 1);
	while ((*stack_a)->index != 1)
		ft_ra(stack_a, 1);
	ft_pb(&stack_b, stack_a, 1);
	ft_process_three_numbs(stack_a);
	ft_pa(&stack_b, stack_a, 1);
	ft_pa(&stack_b, stack_a, 1);
	return (0);
}

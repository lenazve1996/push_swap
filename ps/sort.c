/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:50:47 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 16:17:29 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_move_both_stack(t_lst **stack_a, t_lst **stack_b, t_lst *min_lst)
{
	if (min_lst->up > 0 && min_lst->move > 0)
	{
		ft_rr(stack_a, stack_b, 1);
		min_lst->up--;
		min_lst->move--;
	}
	else if (min_lst->up < 0 && min_lst->move < 0)
	{
		ft_rrr(stack_a, stack_b, 1);
		min_lst->up++;
		min_lst->move++;
	}
}

static void	ft_move_stack_b(t_lst **stack_b, t_lst *min_lst)
{
	if (min_lst->up > 0)
	{
		ft_rb(stack_b, 1);
		min_lst->up--;
	}
	else if (min_lst->up < 0)
	{
		ft_rrb(stack_b, 1);
		min_lst->up++;
	}
}

static void	ft_move_stack_a(t_lst **stack_a, t_lst *min_lst)
{
	if (min_lst->move > 0)
	{
		ft_ra(stack_a, 1);
		min_lst->move--;
	}
	else if (min_lst->move < 0)
	{
		ft_rra(stack_a, 1);
		min_lst->move++;
	}
}

void	ft_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp;
	t_lst	*min_lst;

	tmp = (*stack_b);
	min_lst = tmp;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->sum < min_lst->sum)
			min_lst = tmp;
		tmp = tmp->next;
	}
	while (min_lst->up != 0 || min_lst->move != 0)
	{
		if ((min_lst->up > 0 && min_lst->move > 0) || (min_lst->up < 0 && \
		min_lst->move < 0))
			ft_move_both_stack(stack_a, stack_b, min_lst);
		else if (min_lst->up > 0 || min_lst->up < 0)
			ft_move_stack_b(stack_b, min_lst);
		else if (min_lst->move > 0 || min_lst->move < 0)
			ft_move_stack_a(stack_a, min_lst);
	}
	ft_pa(stack_b, stack_a, 1);
}

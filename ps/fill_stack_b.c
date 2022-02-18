/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:58:47 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 16:16:27 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_lst	*ft_find_numb(t_lst **stack_a, int index)
{
	t_lst	*tmp;

	tmp = *stack_a;
	while (tmp != NULL && tmp->index != index)
		tmp = tmp->next;
	return (tmp);
}

static void	ft_push_numbs(t_lst **stack_a, t_lst **stack_b, int n, int i)
{
	t_lst	*median;
	t_lst	*max;
	t_lst	*min;

	min = ft_find_numb(stack_a, 0);
	max = ft_find_numb(stack_a, n - 1);
	median = ft_find_numb(stack_a, n / 2);
	n = ft_lstsize(*stack_a);
	while ((*stack_a) != NULL && i < n)
	{
		if ((*stack_a) != min && (*stack_a) != max && (*stack_a) != median)
		{
			if ((*stack_a)->index > median->index)
				ft_pb(stack_b, stack_a, 1);
			else if ((*stack_a)->index < median->index)
			{
				ft_pb(stack_b, stack_a, 1);
				if (stack_b != NULL)
					ft_rb(stack_b, 1);
			}
		}
		else
			ft_ra(stack_a, 1);
		i++;
	}
}

void	ft_fill_stack_b(t_lst **stack_a, t_lst **stack_b)
{
	int		n;
	int		i;

	i = 0;
	n = ft_lstsize(*stack_a);
	ft_push_numbs(stack_a, stack_b, n, i);
	ft_process_three_numbs(stack_a);
}

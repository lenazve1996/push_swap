/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:52:36 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 16:16:35 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_put_index(t_lst *tmp, int n)
{
	t_lst	*next;
	int		stop;

	next = tmp->next;
	stop = 0;
	while (next != NULL && stop != 1)
	{
		if (next->numb < tmp->numb)
		{
			if (next->index == -1)
			{
				next->index = n;
				tmp->index = -1;
				tmp = next;
			}
		}
		if (next->next != NULL)
			next = next->next;
		else
			stop = 1;
	}
}

void	ft_define_indexes(t_lst **stack_a)
{
	t_lst	*tmp;
	int		n;
	int		len;

	n = 0;
	len = ft_lstsize(*stack_a);
	while (n < len)
	{
		tmp = *stack_a;
		if (tmp->index == -1)
			tmp->index = n;
		else
		{
			while (tmp->next != NULL && tmp->index != -1)
				tmp = tmp->next;
			tmp->index = n;
		}
		ft_put_index(tmp, n);
		n++;
	}
}

void	ft_define_move_index(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp_b;
	t_lst	*tmp_a;
	int		stop;

	tmp_b = (*stack_b);
	stop = 1;
	while (tmp_b != NULL)
	{
		tmp_a = (*stack_a);
		while (tmp_a->next != NULL && stop)
		{
			if (tmp_a->numb < tmp_b->numb && tmp_b->numb < tmp_a->next->numb)
			{
				tmp_b->move = tmp_a->next->up;
				stop = 0;
			}
			else
				tmp_a = tmp_a->next;
		}
		if (stop && tmp_a->numb < tmp_b->numb && tmp_b->numb < (*stack_a)->numb)
			tmp_b->move = 0;
		tmp_b = tmp_b->next;
		stop = 1;
	}
}

void	ft_define_up_index(t_lst **stack)
{
	t_lst	*tmp;
	int		lst_size;
	int		i;

	tmp = (*stack);
	lst_size = ft_lstsize(*stack);
	i = 0;
	while (i <= lst_size / 2)
	{
		tmp->up = i;
		tmp = tmp->next;
		i++;
	}
	i--;
	if (lst_size % 2 == 0)
		i--;
	while (i > 0)
	{
		tmp->up = -i;
		tmp = tmp->next;
		i--;
	}
}

void	ft_define_sum_index(t_lst **stack_b)
{
	t_lst	*tmp;
	int		up;
	int		move;

	tmp = (*stack_b);
	while (tmp != NULL)
	{
		up = tmp->up;
		if (up < 0)
			up = -up;
		move = tmp->move;
		if (move < 0)
			move = -move;
		tmp->sum = up + move;
		tmp = tmp->next;
	}
}

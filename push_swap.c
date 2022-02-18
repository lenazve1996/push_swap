/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 14:58:15 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_find_numb(t_lst **stack_a, int index)
{
	t_lst	*tmp;

	tmp = *stack_a;
	while (tmp != NULL && tmp->index != index)
		tmp = tmp->next;
	return (tmp);
}

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

void	ft_put_index(t_lst *tmp, int n)
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

void	ft_push_numbs(t_lst **stack_a, t_lst **stack_b, int n, int i)
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

void	ft_move_both_stack(t_lst **stack_a, t_lst **stack_b, t_lst *min_lst)
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

void	ft_move_stack_b(t_lst **stack_b, t_lst *min_lst)
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

void	ft_move_stack_a(t_lst **stack_a, t_lst *min_lst)
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

void	ft_move_sorted_stack(t_lst **stack_a)
{
	t_lst	*tmp;

	ft_define_up_index(stack_a);
	tmp = (*stack_a);
	while (tmp->index != 0)
		tmp = tmp->next;
	while (tmp->up > 0)
	{
		ft_ra(stack_a, 1);
		tmp->up--;
	}
	while (tmp->up < 0)
	{
		ft_rra(stack_a, 1);
		tmp->up++;
	}
}

int	ft_process_big_numbs(t_lst **stack_a)
{
	t_lst	*stack_b;

	stack_b = NULL;
	ft_define_indexes(stack_a);
	ft_fill_stack_b(stack_a, &stack_b);
	while (stack_b != NULL)
	{
		ft_define_up_index(stack_a);
		ft_define_up_index(&stack_b);
		ft_define_move_index(stack_a, &stack_b);
		ft_define_sum_index(&stack_b);
		ft_sort(stack_a, &stack_b);
	}
	ft_move_sorted_stack(stack_a);
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

int	ft_choose_algorithm(t_lst **stack_a)
{
	int		n;

	n = ft_lstsize(*stack_a);
	if (n == 1)
		return (0);
	else if (n == 2)
		return (ft_process_two_numbs(stack_a));
	else if (n == 3)
		return (ft_process_three_numbs(stack_a));
	else if (n == 4)
		return (ft_process_four_numbs(stack_a));
	else if (n == 5)
		return (ft_process_five_numbs(stack_a));
	else if (n > 5)
		return (ft_process_big_numbs(stack_a));
	return (0);
}

void	ft_print_result(t_lst **stack_a)
{
	while ((*stack_a)->next != NULL)
	{
		printf("%d ", (*stack_a)->numb);
		*stack_a = (*stack_a)->next;
	}
	printf("%d\n", (*stack_a)->numb);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	if (ft_parser(argc, argv, &stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		return (ft_putstr_ret("Error\n", 2));
	}
	if (ft_check_order(&stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	ft_choose_algorithm(&stack_a);
	//ft_print_result(&stack_a);
	ft_lstclear(&stack_a);
	return (0);
}

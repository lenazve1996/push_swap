/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 19:13:41 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_lstclear(&stack_a);
	return (0);
}

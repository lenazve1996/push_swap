/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:24:28 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/19 12:14:38 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_check_empty_stack(t_lst **stack_b)
{
	if (*stack_b == NULL)
		return (1);
	else
		return (0);
}

int	ft_save_data(char **instructions)
{
	int		instr_numb;
	int		flag;

	instr_numb = 0;
	flag = 1;
	while (instructions[instr_numb] != NULL || flag)
	{
		if (instr_numb >= 5500)
		{
			ft_free_char_arr(instructions, 0, 0);
			return (ft_putstr_ret("Error\n", 2));
		}
		instructions[instr_numb] = get_next_line(0);
		if (instructions[instr_numb] == NULL)
			flag = 0;
		instr_numb++;
	}
	return (0);
}

int	ft_execute(char **instructions, t_lst **stack_a, t_lst **stack_b)
{
	int		numb;

	numb = 0;
	if (ft_execute_instr(instructions, stack_a, stack_b, numb))
	{
		ft_free_char_arr(instructions, 0, 0);
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		return (1);
	}
	ft_free_char_arr(instructions, 0, 0);
	if (ft_check_order(stack_a) && ft_check_empty_stack(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	char	*instructions[5500];

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (ft_parser(argc, argv, &stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		return (ft_putstr_ret("Error\n", 2));
	}
	if (ft_save_data(instructions))
	{
		ft_lstclear(&stack_a);
		return (1);
	}
	if (ft_execute(instructions, &stack_a, &stack_b))
		return (1);
	return (0);
}

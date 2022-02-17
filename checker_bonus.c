/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:24:28 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/17 19:07:55 by ayajirob@st      ###   ########.fr       */
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

void	ft_save_data(char **instructions)
{
	int		instr_numb;
	char	*line;

	instr_numb = 0;
	line = malloc(1);
	while (line != NULL)
	{
		line = get_next_line(0);
		instructions[instr_numb] = line;
		instr_numb++;
	}
}

void	ft_execute_instr(char **instructions, t_lst **stack_a, t_lst **stack_b)
{
	int	instr_numb;
	int	len;

	instr_numb = 0;
	while (instructions[instr_numb] != NULL)
	{
		len = ft_strlen(instructions[instr_numb]);
		if (ft_strncmp(instructions[instr_numb], "sa\n", len) == 0)
			ft_sa(stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "sb\n", len) == 0)
			ft_sb(stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "pa\n", len) == 0)
			ft_pa(stack_b, stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "pb\n", len) == 0)
			ft_pb(stack_b, stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "ra\n", len) == 0)
			ft_ra(stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "rb\n", len) == 0)
			ft_rb(stack_b, 0);
		else if (ft_strncmp(instructions[instr_numb], "rr\n", len) == 0)
			ft_rr(stack_a, stack_b, 0);
		else if (ft_strncmp(instructions[instr_numb], "rra\n", len) == 0)
			ft_rra(stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "rrb\n", len) == 0)
			ft_rrb(stack_b, 0);
		else if (ft_strncmp(instructions[instr_numb], "rrr\n", len) == 0)
			ft_rrr(stack_a, stack_b, 0);
		instr_numb++;
	}
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
		return (ft_putstr_ret("Error\n", 2));
	if (ft_check_order(&stack_a) == 1)
		return (0);
	ft_save_data(instructions);
	ft_execute_instr(instructions, &stack_a, &stack_b);
	ft_free_char_arr(instructions, 0);
	if (ft_check_order(&stack_a) && ft_check_empty_stack(&stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

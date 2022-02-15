/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:24:28 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/15 10:37:38 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_print_result(t_lst **stack_a)
{
	while ((*stack_a)->next != NULL)
	{
		printf("%d ", (*stack_a)->numb);
		*stack_a = (*stack_a)->next;
	}
	printf("%d\n", (*stack_a)->numb);
}

int main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	char	*line;
	char	*instructions[5500];
	int		instr_numb;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	//if (argc < 2)
	//	return (ft_putstr_ret("Error\n", 2));
	if (argc == 1)
		return (0);
	if (ft_parser(argc, argv, &stack_a) == 1)
		return (ft_putstr_ret("Error\n", 2));
	if (ft_check_order(&stack_a) == 1)
		return (0);
	// ft_print_result(&stack_a);
	line = malloc(1);
	instr_numb = 0;
	while (line != NULL)
	{
		line = get_next_line(0);
		instructions[instr_numb++] = line;
	}
	instr_numb = 0;
	while (instructions[instr_numb] != NULL)
	{
		len = ft_strlen(instructions[instr_numb]);
		if (ft_strncmp(instructions[instr_numb], "sa", len) == 0)
			ft_sa(&stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "sb", len) == 0)
			ft_sb(&stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "pa", len) == 0)
			ft_pa(&stack_b, &stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "pb", len) == 0)
			ft_pb(&stack_b, &stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "ra", len) == 0)
			ft_ra(&stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "rb", len) == 0)
			ft_rb(&stack_b, 0);
		else if (ft_strncmp(instructions[instr_numb], "rr", len) == 0)
			ft_rr(&stack_a, &stack_b, 0);
		else if (ft_strncmp(instructions[instr_numb], "rra", len) == 0)
			ft_rra(&stack_a, 0);
		else if (ft_strncmp(instructions[instr_numb], "rrb", len) == 0)
			ft_rrb(&stack_b, 0);
		else if (ft_strncmp(instructions[instr_numb], "rrr", len) == 0)
			ft_rrr(&stack_a, &stack_b, 0);
	}
	if (ft_check_order(&stack_a) == 1)
		printf("ORDER IS FINE\n");
	else 
		printf("ORDER IS BAD\n");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:24:28 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 13:36:27 by ayajirob@st      ###   ########.fr       */
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

void	ft_execute_instr(char **instr, t_lst **st_a, t_lst **st_b, int numb)
{
	while (instr[numb] != NULL)
	{
		if (ft_strcmp(instr[numb], "sa\n") == 0)
			ft_sa(st_a, 0);
		else if (ft_strcmp(instr[numb], "sb\n") == 0)
			ft_sb(st_a, 0);
		else if (ft_strcmp(instr[numb], "pa\n") == 0)
			ft_pa(st_b, st_a, 0);
		else if (ft_strcmp(instr[numb], "pb\n") == 0)
			ft_pb(st_b, st_a, 0);
		else if (ft_strcmp(instr[numb], "ra\n") == 0)
			ft_ra(st_a, 0);
		else if (ft_strcmp(instr[numb], "rb\n") == 0)
			ft_rb(st_b, 0);
		else if (ft_strcmp(instr[numb], "rr\n") == 0)
			ft_rr(st_a, st_b, 0);
		else if (ft_strcmp(instr[numb], "rra\n") == 0)
			ft_rra(st_a, 0);
		else if (ft_strcmp(instr[numb], "rrb\n") == 0)
			ft_rrb(st_b, 0);
		else if (ft_strcmp(instr[numb], "rrr\n") == 0)
			ft_rrr(st_a, st_b, 0);
		numb++;
	}
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	char	*instructions[5500];
	int		numb;

	numb = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (ft_parser(argc, argv, &stack_a) == 1)
		return (ft_putstr_ret("Error\n", 2));
	if (ft_check_order(&stack_a) == 1)
		return (0);
	ft_save_data(instructions);
	ft_execute_instr(instructions, &stack_a, &stack_b, numb);
	ft_free_char_arr(instructions, 0, 0);
	if (ft_check_order(&stack_a) && ft_check_empty_stack(&stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

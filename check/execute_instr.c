/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:08:50 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 19:13:02 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	execute_s_instr(char **instr, t_lst **st_a, t_lst **st_b, int numb)
{
	if (ft_strcmp(instr[numb], "sa\n") == 0)
		ft_sa(st_a, 0);
	else if (ft_strcmp(instr[numb], "sb\n") == 0)
		ft_sb(st_a, 0);
	else if (ft_strcmp(instr[numb], "ss\n") == 0)
		ft_ss(st_a, st_b, 0);
}

static void	execute_p_instr(char **instr, t_lst **st_a, t_lst **st_b, int numb)
{
	if (ft_strcmp(instr[numb], "pa\n") == 0)
		ft_pa(st_b, st_a, 0);
	else if (ft_strcmp(instr[numb], "pb\n") == 0)
		ft_pb(st_b, st_a, 0);
}

int	ft_execute_instr(char **instr, t_lst **st_a, t_lst **st_b, int numb)
{
	while (instr[numb] != NULL)
	{
		if (ft_strcmp(instr[numb], "sa\n") == 0 || ft_strcmp(instr[numb], \
		"sb\n") == 0 || ft_strcmp(instr[numb], "ss\n") == 0)
			execute_s_instr(instr, st_a, st_b, numb);
		else if (ft_strcmp(instr[numb], "pa\n") == 0 || \
		ft_strcmp(instr[numb], "pb\n") == 0)
			execute_p_instr(instr, st_a, st_b, numb);
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
		else
			return (ft_putstr_ret("Error\n", 2));
		numb++;
	}
	return (0);
}

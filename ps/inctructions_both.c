/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inctructions_both.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:28:35 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 19:13:14 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (write_flag)
		write(1, "rrr\n", 4);
}

void	ft_rr(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (write_flag)
		write(1, "rr\n", 3);
}

void	ft_ss(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (write_flag)
		write(1, "rr\n", 3);
}

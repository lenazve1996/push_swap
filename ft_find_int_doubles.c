/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_int_doubles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:21:54 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/01/25 19:33:32 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_int_doubles(t_lst **stack_a)
{
	t_lst	*tmp_lst;
	t_lst	*next_lst;
	
	tmp_lst = *stack_a;
	while (tmp_lst != NULL)
	{
		//printf("%d\n", tmp_lst->numb);
		next_lst = tmp_lst->next;
		while (next_lst != NULL)
		{
			if (tmp_lst->numb == next_lst->numb)
				return (1);
			next_lst = next_lst->next;
		}
		tmp_lst = tmp_lst->next;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:42:55 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/17 14:52:00 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_lst **lst)
{
	t_lst	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
	}
}

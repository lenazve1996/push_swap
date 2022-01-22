/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:03:43 by ayajirob          #+#    #+#             */
/*   Updated: 2021/11/21 14:38:32 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	size_of_lst;

	size_of_lst = ft_lstsize(lst);
	while (size_of_lst--)
	{
		f(lst->content);
		lst = lst->next;
	}
}

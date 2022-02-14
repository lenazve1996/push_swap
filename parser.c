/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:33:03 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/14 18:54:56 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_check_order(t_lst **stack_a)
{
	t_lst	*tmp_lst;
	
	tmp_lst = *stack_a;
	while (tmp_lst->next != NULL)
	{
		if (tmp_lst->numb > tmp_lst->next->numb)
			return (0);
		else
			tmp_lst = tmp_lst->next;
	}
	return (1);
}

static int	ft_check_characters(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit_orsign(str[i]) == 0)
			return (1);
		if (i == 0 && str[i + 1] == '\0' && (str[i] == '+' || str[i] == '-'))
			return (1);
		if (i == 0 && (str[i + 1] == '+' || str[i + 1] == '-') && \
		(str[i] == '+' || str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_fill_stack_a(char *str, t_lst **stack_a)
{
	long long int	numb;
	
	if (ft_check_characters(str) == 1)
		return (1);
	numb = ft_atoi(str);
	if (numb < -2147483648 || numb > 2147483647)
		return (1);
	if (stack_a == NULL)
		*stack_a = ft_lstnew_ps(numb);
	else
	{
		ft_lstadd_back_ps(stack_a, ft_lstnew_ps(numb));
	}
	return (0);
}

int	ft_parser(int ac, char **av, t_lst **stack_a)
{
	int		i;
	int		c;
	char	**tmp_arr;
	
	i = 1;
	while (i < ac)
	{
		c = 0;
		tmp_arr = ft_split(av[i], ' ');
		if (tmp_arr == NULL)
			return (1);
		while (tmp_arr[c] != NULL)
		{
			if (ft_fill_stack_a(tmp_arr[c], stack_a) == 1)
				return (1);
			c++;
		}
		i++;
	}
	if (ft_find_int_doubles(stack_a) == 1)
		return (1);
	return (0);
}
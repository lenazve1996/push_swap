/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/01/25 16:35:04 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa()
{
	write(1, "sa\n", 3);
}

int ft_process_two_numbs(t_lst **stack_a)
{
	t_lst	*tmp_elem;

	tmp_elem = *stack_a;
	if (tmp_elem->numb > tmp_elem->next->numb)
		ft_sa();
	return (0);
}

int	ft_choose_algorithm(t_lst **stack_a)
{
	int		n;
	
	n = ft_lstsize(*stack_a);

	if (n == 1)
		return (0);
	else if (n == 2)
	{
		ft_process_two_numbs(stack_a);
		return(0);
	}
	return (0);
}

int	ft_check_characters(char *str)
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

int	ft_fill_stack_a(char *str, t_lst **stack_a)
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
	int				i;
	int				c;
	char			**tmp_arr;
	
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

int		main(int argc, char **argv)
{
	t_lst	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (ft_putstr_ret("Error\n", 2));
	if (ft_parser(argc, argv, &stack_a) == 1)
		return (ft_putstr_ret("Error\n", 2));
	ft_choose_algorithm(&stack_a);
	return (0);
}
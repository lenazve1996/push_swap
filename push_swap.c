/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/01/23 19:32:46 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_space(char *str)
{
	int i;
	
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_process_numb_in_quotes(char *str)
{
	char	**array;
	int		i;
	
	i = 0;
	array = ft_split(str, ' ');
	if (array == NULL)
		return (NULL);
	return (array);
}

int	ft_fill_stack_a(char *str, t_lst **stack_a)
{
	int	i;
	int	numb;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit_orsign(str[i]) == 0)
			return (1);
		i++;
	}
	numb = ft_atoi(str);
	if (stack_a == NULL)
		*stack_a = ft_lstnew_ps(numb);
	else
	{
		ft_lstadd_back_ps(stack_a, ft_lstnew_ps(numb));
	}
	return (0);
}

int	ft_parser(int ac, char **av)
{
	int				i;
	int				n;
	int				c;
	char			**tmp_arr;
	static int		b;
	t_lst			*stack_a;
	
	stack_a = NULL;
	n = 0;
	i = 1;
	b = 0;
	c = 0;
	while (i < ac)
	{
		printf("%s\n", av[i]);
		if (ft_find_space(av[i]) == 1)
		{
			tmp_arr = ft_process_numb_in_quotes(av[i]);
			if (tmp_arr == NULL)
				return (1);
			else
			{
				while (tmp_arr[c] != NULL)
				{
					if (ft_fill_stack_a(tmp_arr[c], &stack_a) == 1)
						return (1);
					c++;
				}
			}
		}
		else
		{
			printf("here\n");
			if (ft_fill_stack_a(av[i], &stack_a) == 1)
				return (1);
		}
		i++;
	}
	if (ft_find_int_doubles(&stack_a) == 1)
	{
		printf("here5\n");
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_putstr_ret("Error\n", 2));
	if (ft_parser(argc, argv) == 1)
		return (ft_putstr_ret("Error\n", 2));
	return (0);
}
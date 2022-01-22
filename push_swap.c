/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/01/22 18:17:33 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"
#include "./libft/libft.h"

int	ft_parser(int ac, char **av)
{
	int	i;
	int	j;
	int	n;
	int	stack_a[10];
	
	n = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit_orsign(av[i][j]) == 0)
			{
				return(ft_putstr_ret("Error\nSome arguments are not integers\n"\
				, 2));
			}
			stack_a[n++] = ft_atoi(av[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return(ft_putstr_ret("Error\nUsage: ./push_swap 1 2\n", 2));
	if (ft_parser(argc, argv) == 1)
		return (1);
	return (0);
}
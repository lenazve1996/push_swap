/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/09 17:34:32 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printf_index(t_lst **stack_a)
{
	t_lst *tmp;

	if ((*stack_a) == NULL)
		printf("FALED, not stack\n");
	else
	{
		tmp = *stack_a;
		while (tmp->next != NULL)
		{
			printf("n-> %3d 	", tmp->numb);
			printf("i-> %3d \n", tmp->index);
			tmp = tmp->next;
		}
		printf("n-> %3d 	", tmp->numb);
		printf("i-> %3d \n\n", tmp->index);
	}
}

void	ft_sa(t_lst **stack_a, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *new_head;

	tmp_elem = *stack_a;
	new_head = tmp_elem->next;
	tmp_elem->next = new_head->next;
	new_head->next = tmp_elem;
	*stack_a = new_head;
	if (write_flag)
		write(1, "sa\n", 3);
}

void	ft_sb(t_lst **stack_b, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *new_head;

	tmp_elem = *stack_b;
	new_head = tmp_elem->next;
	tmp_elem->next = new_head->next;
	new_head->next = tmp_elem;
	*stack_b = new_head;
	if (write_flag)
		write(1, "sb\n", 3);
}

void	ft_ss(t_lst **stack_b, t_lst **stack_a)
{	
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void	ft_pa(t_lst **stack_b, t_lst **stack_a)
{
	t_lst	*tmp_elem;

	if (stack_b != NULL)
	{
		tmp_elem = *stack_b;
		*stack_b = tmp_elem->next;
		ft_lstadd_front_ps(stack_a, tmp_elem);
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_lst **stack_b, t_lst **stack_a)
{
	t_lst *tmp_elem;

	if (stack_b != NULL)
	{
		tmp_elem = *stack_a;
		*stack_a = tmp_elem->next;
		ft_lstadd_front_ps(stack_b, tmp_elem);
	}
	write(1, "pb\n", 3);
}

void	ft_ra(t_lst **stack_a, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *last_elem;

	tmp_elem = *stack_a;
	*stack_a = tmp_elem->next;
	last_elem = ft_lstlast_ps(*stack_a);
	last_elem->next = tmp_elem;
	tmp_elem->next = NULL;
	if (write_flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_lst **stack_b, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *last_elem;

	tmp_elem = *stack_b;
	*stack_b = tmp_elem->next;
	last_elem = ft_lstlast_ps(*stack_b);
	last_elem->next = tmp_elem;
	tmp_elem->next = NULL;
	if (write_flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_lst **stack_a, t_lst **stack_b)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write(1, "rra\n", 3);
}

void	ft_rra(t_lst **stack_a, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *last_elem;

	last_elem = ft_lstlast_ps(*stack_a);
	tmp_elem = *stack_a;
	while (tmp_elem->next->next != NULL)
		tmp_elem = tmp_elem->next;
	tmp_elem->next = NULL;
	ft_lstadd_front_ps(stack_a, last_elem);
	if (write_flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_lst **stack_b, int write_flag)
{
	t_lst *tmp_elem;
	t_lst *last_elem;

	last_elem = ft_lstlast_ps(*stack_b);
	tmp_elem = *stack_b;
	while (tmp_elem->next->next != NULL)
		tmp_elem = tmp_elem->next;
	tmp_elem->next = NULL;
	ft_lstadd_front_ps(stack_b, last_elem);
	if (write_flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_lst **stack_a, t_lst **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}

int ft_process_two_numbs(t_lst **stack_a)
{
	t_lst	*tmp_elem;

	tmp_elem = *stack_a;
	if (tmp_elem->numb > tmp_elem->next->numb)
		ft_sa(stack_a, 1);
	return (0);
}

int ft_process_three_numbs(t_lst **stack_a)
{
	int a;	
	int b;	
	int c;

	a = (*stack_a)->numb;
	b = (*stack_a)->next->numb;
	c = (*stack_a)->next->next->numb;
	if (a < b && a < c && b > c)
	{
		ft_rra(stack_a, 1);
		ft_sa(stack_a, 1);
		return (0);
	}
	else if (a > b && b < c && a < c)
	{
		ft_sa(stack_a, 1);
	}
	else if (a < b && a > c && b > c)
	{
		ft_rra(stack_a, 1);
	}
	else if (a > b && a > c && b < c)
	{
		ft_ra(stack_a, 1);
	}
	else if (a > b & a > c && b > c)
	{
		ft_sa(stack_a, 1);
		ft_rra(stack_a, 1);
	}
	return (0);
}

t_lst	*ft_find_numb(t_lst **stack_a, int index)
{
	t_lst	*tmp;

	tmp = *stack_a;
	while (tmp != NULL && tmp->index != index)
		tmp = tmp->next;
	return (tmp);
	
}

void	ft_fill_stack_b(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*median;
	t_lst	*max;
	t_lst	*min;
	int		n;
	int		i;

	n = ft_lstsize(*stack_a);
	i = 0;
	min = ft_find_numb(stack_a, 0);
	max = ft_find_numb(stack_a, n - 1);
	median =  ft_find_numb(stack_a, n / 2);
	//printf("%d\n", min->index);
	//printf("%d\n", max->index);
	//printf("%d\n", median->index);
	while ((*stack_a) != NULL && i < n)
	{
		if ((*stack_a) != min && (*stack_a) != max && (*stack_a) != median)
		{
			//printf("---> %d\n", (*stack_a)->index); //dell
			if ((*stack_a)->index < median->index)
				ft_pb(stack_b, stack_a);
			else if ((*stack_a)->index > median->index)
			{
				//printf("---> HEY MAMBO\n"); //dell
				ft_pb(stack_b, stack_a);
				ft_rb(stack_b, 1);
			}
				
		}
		else 
			ft_ra(stack_a, 1);
		//printf("\nSTACK_A:\n");
		//ft_printf_index(stack_a);
		//printf("STACK_B:\n");
		//ft_printf_index(stack_b);
		i++;
	}
}

void	ft_process_big_numbs(t_lst **stack_a)
{
	t_lst	*stack_b;
	
	stack_b = NULL;
	ft_fill_stack_b(stack_a, &stack_b);
	printf("\nSTACK_A:\n");
	ft_printf_index(stack_a);
	printf("STACK_B:\n");
	ft_printf_index(&stack_b);
	//while ((stack_b)->next != NULL)
	//{
	//	printf("n->%d ", (stack_b)->numb);
	//	printf("i->%d \n", (stack_b)->index);
	//	*stack_a = (stack_b)->next;	
	//}
	//printf("n->%d ", (stack_b)->numb);
	//printf("i->%d \n\n", (stack_b)->index);
	
}

int	ft_choose_algorithm(t_lst **stack_a)
{
	int		n;
	
	n = ft_lstsize(*stack_a);
	printf("%d\n", n);
	if (n == 1)
		return (0);
	else if (n == 2)
	{
		ft_process_two_numbs(stack_a);
		return(0);
	}
	else if (n == 3)
	{
		ft_process_three_numbs(stack_a);
		return(0);
	}
	else if (n > 3)
	{
		ft_process_big_numbs(stack_a);
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

void	ft_define_index(t_lst **stack_a)
{
	t_lst	*tmp;
	t_lst	*next;
	int		n;
	int		len;
	int		stop;
	
	stop = 0;
	//tmp = *stack_a;
	n = 0;
	len = ft_lstsize(*stack_a);
	while (n < len)
	{
		tmp = *stack_a;
		stop = 0;
		if (tmp->index == -1)
			tmp->index = n;
		else
		{
			while(tmp->next != NULL && tmp->index != -1)
				tmp = tmp->next;
			tmp->index = n;
		}
		next = tmp->next;
		while (next != NULL && stop != 1)
		{
			//printf("tmp->numb %d \n", tmp->numb); //dell
			//printf("tmp->index %d \n", tmp->index); //dell
			//printf("next->numb %d \n", next->numb); //dell
			//printf("next->index %d \n\n", next->index); //dell
			if (next->numb < tmp->numb)
			{
				if (next->index == -1)
				{
					next->index = n;
					tmp->index = -1;
					tmp = next;
				}
			}
			if (next->next != NULL)
				next = next->next;
			else
				stop = 1;
		}
		n++;
	}
}

void	ft_print_result(t_lst **stack_a)
{
	while ((*stack_a)->next != NULL)
	{
		printf("%d ", (*stack_a)->numb);
		*stack_a = (*stack_a)->next;
	}
	printf("%d\n", (*stack_a)->numb);
}

int		main(int argc, char **argv)
{
	t_lst	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (ft_putstr_ret("Errordd\n", 2)); //dell
	if (ft_parser(argc, argv, &stack_a) == 1)
		return (ft_putstr_ret("Erroraa\n", 2)); //dell
	if (ft_check_order(&stack_a) == 1)
		return (0);
	ft_define_index(&stack_a);
	ft_printf_index(&stack_a);
	ft_choose_algorithm(&stack_a);
	ft_print_result(&stack_a);
	return (0);
	
}
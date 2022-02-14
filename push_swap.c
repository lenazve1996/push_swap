/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:06:43 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/14 19:42:57 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_find_numb(t_lst **stack_a, int index)
{
	t_lst	*tmp;

	tmp = *stack_a;
	while (tmp != NULL && tmp->index != index)
		tmp = tmp->next;
	return (tmp);
	
}

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
			printf("i-> %3d		", tmp->index);
			printf("u-> %3d		", tmp->up);
			printf("m-> %3d		", tmp->move);
			printf("s-> %3d		\n", tmp->sum);
			tmp = tmp->next;
		}
		printf("n-> %3d 	", tmp->numb);
		printf("i-> %3d		", tmp->index);
		printf("u-> %3d		", tmp->up);
		printf("m-> %3d		", tmp->move);
		printf("s-> %3d		\n\n", tmp->sum);
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

//void	ft_ss(t_lst **stack_b, t_lst **stack_a)
//{	
//	ft_sa(stack_a, 0);
//	ft_sb(stack_b, 0);
//	write(1, "ss\n", 3);
//}

void	ft_pa(t_lst **stack_b, t_lst **stack_a, int write_flag)
{
	t_lst	*tmp_elem;

	if (stack_b != NULL)
	{
		tmp_elem = *stack_b;
		*stack_b = tmp_elem->next;
		ft_lstadd_front_ps(stack_a, tmp_elem);
	}
	if (write_flag)
		write(1, "pa\n", 3);
}

void	ft_pb(t_lst **stack_b, t_lst **stack_a, int write_flag)
{
	t_lst *tmp_elem;

	if (stack_b != NULL)
	{
		tmp_elem = *stack_a;
		*stack_a = tmp_elem->next;
		ft_lstadd_front_ps(stack_b, tmp_elem);
	}
	if (write_flag)
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

	if ((*stack_b) != NULL && (*stack_b)
	->next != NULL)
	{
		tmp_elem = *stack_b;
		*stack_b = tmp_elem->next;
		tmp_elem->next = NULL;
		last_elem = ft_lstlast_ps(*stack_b);
		last_elem->next = tmp_elem;
	}
	if (write_flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (write_flag)
		write(1, "rr\n", 3);
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

void	ft_rrr(t_lst **stack_a, t_lst **stack_b, int write_flag)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (write_flag)
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

void	ft_define_index(t_lst **stack_a)
{
	t_lst	*tmp;
	t_lst	*next;
	int		n;
	int		len;
	int		stop;
	
	stop = 0;
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

int	ft_process_five_numbs(t_lst **stack_a)
{
	t_lst	*min;
	t_lst	*stack_b;
	
	stack_b = NULL;
	ft_define_index(stack_a);
	min = ft_find_numb(stack_a, 0);
	while ((*stack_a)->index != 0)
		ft_ra(stack_a, 1);
	ft_pb(&stack_b, stack_a, 1);
	min = ft_find_numb(stack_a, 1);
	while ((*stack_a)->index != 1)
		ft_ra(stack_a, 1);
	ft_pb(&stack_b, stack_a, 1);
	ft_process_three_numbs(stack_a);
	ft_pa(&stack_b, stack_a, 1);
	ft_pa(&stack_b, stack_a, 1);
	return (0);
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
	while ((*stack_a) != NULL && i < n)
	{
		if ((*stack_a) != min && (*stack_a) != max && (*stack_a) != median)
		{
			if ((*stack_a)->index < median->index)
				ft_pb(stack_b, stack_a, 1);
			else if ((*stack_a)->index > median->index)
			{
				ft_pb(stack_b, stack_a, 1);
				if (stack_b != NULL)
					ft_rb(stack_b, 1);
			}
				
		}
		else 
			ft_ra(stack_a, 1);
		i++;
	}
	ft_process_three_numbs(stack_a);
	ft_ra(stack_a, 1);
}

void	ft_define_move_index(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tmp_b;
	t_lst	*tmp_a;
	int		stop;
	
	tmp_b = (*stack_b);
	stop = 1;
	while (tmp_b != NULL)
	{
		tmp_a = (*stack_a);
		while (tmp_a->next != NULL && stop)
		{
			if (tmp_a->numb < tmp_b->numb && tmp_b->numb < tmp_a->next->numb)
			{
				tmp_b->move = tmp_a->next->up;
				stop = 0;
			}
			else
				tmp_a = tmp_a->next;
		}
		if (stop && tmp_a->numb < tmp_b->numb && tmp_b->numb < (*stack_a)->numb)
			tmp_b->move = 0;
		tmp_b = tmp_b->next;
		stop = 1;
	}
}

void	ft_define_up_index(t_lst **stack)
{
	t_lst	*tmp;
	int		lst_size;
	int		i;
	
	tmp = (*stack);
	lst_size = ft_lstsize(*stack);
	i = 0;
	while (i <= lst_size / 2)
	{
		tmp->up = i;
		tmp = tmp->next;
		i++;
	}
	i--;
	if (lst_size % 2 == 0)
		i--;
	while (i > 0)
	{
		tmp->up = -i;
		tmp = tmp->next;
		i--;
	}
}

void	ft_define_sum_index(t_lst **stack_b)
{
	t_lst	*tmp;
	int		up;
	int		move;
	
	tmp = (*stack_b);
	while (tmp != NULL)
	{
		up = tmp->up;
		if (up < 0)
			up = -up;
		move = tmp->move;
		if (move < 0)
			move = -move;
		tmp->sum = up + move;
		tmp = tmp->next;
	}
}

void	ft_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst *tmp;
	t_lst *min_lst;

	tmp = (*stack_b);
	min_lst = tmp;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->sum < min_lst->sum)
			min_lst = tmp;
		tmp = tmp->next;
	}
	while (min_lst->up != 0 || min_lst->move != 0)
	{
		if (min_lst->up > 0 && min_lst->move > 0)
		{
			ft_rr(stack_a, stack_b, 1);
			min_lst->up--;
			min_lst->move--;
		}
		else if (min_lst->up < 0 && min_lst->move < 0)
		{
			ft_rrr(stack_a, stack_b, 1);
			min_lst->up++;
			min_lst->move++;
		}
		else if (min_lst->up > 0)
		{
			ft_rb(stack_b, 1);
			min_lst->up--;
		}
		else if (min_lst->move > 0)
		{
			ft_ra(stack_a, 1);
			min_lst->move--;
		}
		else if (min_lst->up < 0)
		{
			ft_rrb(stack_b, 1);
			min_lst->up++;
		}
		else if (min_lst->move < 0)
		{
			ft_rra(stack_a, 1);
			min_lst->move++;
		}
	}
	//while (min_lst->move != 0)
	//{
	//	if (min_lst->move > 0)
	//	{
	//		ft_ra(stack_a, 1);
	//		min_lst->move--;
	//	}
	//	else if (min_lst->move < 0)
	//	{
	//		ft_rra(stack_a, 1);
	//		min_lst->move++;
	//	}
	//}
	ft_pa(stack_b, stack_a, 1);
}

int	ft_process_big_numbs(t_lst **stack_a)
{
	t_lst	*stack_b;
	
	stack_b = NULL;
	ft_define_index(stack_a);
	//ft_printf_index(stack_a);
	ft_fill_stack_b(stack_a, &stack_b);
	//printf("\nSTACK_A:\n");
	//ft_printf_index(stack_a);
	//printf("STACK_B:\n");
	//ft_printf_index(&stack_b);
	while (stack_b != NULL)
	{
		ft_define_up_index(stack_a);
		ft_define_up_index(&stack_b);
		ft_define_move_index(stack_a, &stack_b);
		ft_define_sum_index(&stack_b);
		//printf("\nSTACK_A:\n");
		//ft_printf_index(stack_a);
		//printf("STACK_B:\n");
		//ft_printf_index(&stack_b);
		ft_sort(stack_a, &stack_b);
	}
	while ((*stack_a)->index != 0)
	{
		ft_ra(stack_a, 1);
	}
	return (0);
}

int	ft_process_four_numbs(t_lst **stack_a)
{
	t_lst	*min;
	t_lst	*stack_b;
	
	stack_b = NULL;
	ft_define_index(stack_a);
	min = ft_find_numb(stack_a, 0);
	while ((*stack_a)->index != 0)
		ft_ra(stack_a, 1);
	ft_pb(&stack_b, stack_a, 1);
	ft_process_three_numbs(stack_a);
	ft_pa(&stack_b, stack_a, 1);
	return (0);
}

int	ft_choose_algorithm(t_lst **stack_a)
{
	int		n;
	
	n = ft_lstsize(*stack_a);
	if (n == 1)
		return (0);
	else if (n == 2)
		return(ft_process_two_numbs(stack_a));
	else if (n == 3)
		return(ft_process_three_numbs(stack_a));
	else if (n == 4)
		return(ft_process_four_numbs(stack_a));
	else if (n == 5)
		return(ft_process_five_numbs(stack_a));
	else if (n > 5)
		return(ft_process_big_numbs(stack_a));
	return (0);
}

//int	ft_check_characters(char *str)
//{
//	int	i;
	
//	i = 0;
//	while (str[i] != '\0')
//	{
//		if (ft_isdigit_orsign(str[i]) == 0)
//			return (1);
//		if (i == 0 && str[i + 1] == '\0' && (str[i] == '+' || str[i] == '-'))
//			return (1);
//		if (i == 0 && (str[i + 1] == '+' || str[i + 1] == '-') && \
//		(str[i] == '+' || str[i] == '-'))
//			return (1);
//		i++;
//	}
//	return (0);
//}

//int	ft_fill_stack_a(char *str, t_lst **stack_a)
//{
//	long long int	numb;
	
//	if (ft_check_characters(str) == 1)
//		return (1);
//	numb = ft_atoi(str);
//	if (numb < -2147483648 || numb > 2147483647)
//		return (1);
//	if (stack_a == NULL)
//		*stack_a = ft_lstnew_ps(numb);
//	else
//	{
//		ft_lstadd_back_ps(stack_a, ft_lstnew_ps(numb));
//	}
//	return (0);
//}

//int	ft_parser(int ac, char **av, t_lst **stack_a)
//{
//	int		i;
//	int		c;
//	char	**tmp_arr;
	
//	i = 1;
//	while (i < ac)
//	{
//		c = 0;
//		tmp_arr = ft_split(av[i], ' ');
//		if (tmp_arr == NULL)
//			return (1);
//		while (tmp_arr[c] != NULL)
//		{
//			if (ft_fill_stack_a(tmp_arr[c], stack_a) == 1)
//				return (1);
//			c++;
//		}
//		i++;
//	}
//	if (ft_find_int_doubles(stack_a) == 1)
//		return (1);
//	return (0);
//}

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
	//if (argc < 2)
	//	return (ft_putstr_ret("Error\n", 2));
	if (argc == 1)
		return (0);
	if (ft_parser(argc, argv, &stack_a) == 1)
		return (ft_putstr_ret("Error\n", 2));
	if (ft_check_order(&stack_a) == 1)
		return (0);
	ft_choose_algorithm(&stack_a);
	//ft_print_result(&stack_a);
	//if (ft_check_order(&stack_a) == 1)
	//	printf("ORDER IS FINE\n");
	return (0);
}
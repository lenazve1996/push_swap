/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob@student.42.fr <ayajirob>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:32:42 by ayajirob@st       #+#    #+#             */
/*   Updated: 2022/02/18 13:32:18 by ayajirob@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_char_arr(char **arr, int arr_free_flag, int ret_flag)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i++]);
	}
	if (arr_free_flag)
		free(arr);
	return (ret_flag);
}

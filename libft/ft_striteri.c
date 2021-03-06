/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:43:43 by ayajirob          #+#    #+#             */
/*   Updated: 2021/12/05 15:43:44 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	n;

	n = 0;
	while (*s)
	{
		f(n, s);
		s++;
		n++;
	}
	*s = '\0';
}

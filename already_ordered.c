/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_ordered.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:24:04 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 10:44:58 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_ordered(t_list **a_list)
{
	int		i;
	t_list	*first;

	i = 0;
	first = (*a_list);
	while ((*a_list) != NULL)
	{
		if (i != (*a_list)->index)
		{
			(*a_list) = first;
			return (1);
		}
		i++;
		(*a_list) = (*a_list)->next;
	}
	(*a_list) = first;
	return (0);
}

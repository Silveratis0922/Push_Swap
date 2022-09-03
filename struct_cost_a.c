/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cost_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:41:25 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/02 15:03:58 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	struct_cost_a(t_list **a_list, t_list **b_list)
{
	t_list	*first;
	int	size;

	first = (*b_list);
	size = ft_lstsize(*a_list);
	while ((*b_list) != NULL)
	{
		if ((*b_list)->t_pos <= size / 2)
			(*b_list)->cost_a = (*b_list)->t_pos;
		else if ((*b_list)->t_pos == size)
			(*b_list)->cost_a = 0;
		else
			(*b_list)->cost_a = (*b_list)->t_pos - size;
		(*b_list) = (*b_list)->next;
	}
	(*b_list) = first;
}

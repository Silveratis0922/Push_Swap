/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:20:28 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 11:48:36 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_on_top(t_list **a_list, int cost_b)
{
	while (cost_b != 0)
	{
		if (cost_b > 0)
		{
			lst_rotate(a_list, 5);
			cost_b--;
		}
		else
		{
			lst_reverse_rotate(a_list, 7);
			cost_b++;
		}
	}
}

void	mini_to_the_top(t_list **a_list)
{
	t_list	*first;
	t_list	*index_zero;
	int		cost_b;

	first = (*a_list);
	index_zero = (*a_list);
	while ((*a_list) != NULL)
	{
		if ((*a_list)->index == 0)
		{
			index_zero = (*a_list);
			cost_b = index_zero->cost_b;
			break ;
		}
		(*a_list) = (*a_list)->next;
	}
	(*a_list) = first;
	move_min_on_top(a_list, cost_b);
}

t_list	*next_push_a(t_list **b_list)
{
	t_list	*first;
	t_list	*save;
	int		nbr_save;
	int		nbr;

	save = (*b_list);
	first = (*b_list);
	(*b_list) = (*b_list)->next;
	while ((*b_list) != NULL)
	{
		nbr_save = abs(save->cost_a) + abs(save->cost_b);
		nbr = abs((*b_list)->cost_a) + abs((*b_list)->cost_b);
		if (nbr < nbr_save)
			save = (*b_list);
		(*b_list) = (*b_list)->next;
	}
	(*b_list) = first;
	return (save);
}

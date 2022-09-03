/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:13:24 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/03 15:10:37 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	struct_pos(t_list **list)
{
	t_list	*first;
	int		pos;

	pos = 0;
	first = (*list);
	while ((*list) != NULL)
	{
		(*list)->pos = pos;
		(*list) = (*list)->next;
		pos++;
	}
	(*list) = first;
}

t_list	*found_max(t_list **a_list, t_list *index_max)
{
	if ((*a_list)->index > index_max->index)
		index_max = (*a_list);
	return (index_max);
}

t_list	*found_min(t_list **a_list, t_list *index_min)
{
	if ((*a_list)->index < index_min->index)
		index_min = (*a_list);
	return (index_min);
}

void	struct_t_pos_bis(t_list **a_list, t_list **b_list)
{
	t_list	*first_a;

	first_a = (*a_list);
	while (!((*b_list)->index > (*a_list)->index
			&& (*b_list)->index < (*a_list)->next->index))
	{
		if ((*a_list)->next == NULL)
		{
			(*b_list)->t_pos = 0;
			break ;
		}
		(*a_list) = (*a_list)->next;
	}
	if ((*a_list)->next != NULL)
		(*b_list)->t_pos = (*a_list)->next->pos;
	(*a_list) = first_a;
}

void	struct_t_pos(t_list **a_list, t_list **b_list)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*index_max;
	t_list	*index_min;
	int		nbr;

	first_a = (*a_list);
	first_b = (*b_list);
	index_max = (*a_list);
	index_min = (*a_list);
	while ((*b_list) != NULL)
	{
		nbr = 0;
		while ((*a_list) != NULL && (*b_list)->index > (*a_list)->index)
		{
			index_max = found_max(a_list, index_max);
			(*a_list) = (*a_list)->next;
			nbr++;
		}
		(*a_list) = first_a;
		if (nbr == ft_lstsize(*a_list))
			(*b_list)->t_pos = index_max->pos + 1;
		else if (nbr != ft_lstsize (*a_list))
		{
			nbr = 0;
			while ((*a_list) != NULL && (*b_list)->index < (*a_list)->index)
			{
				index_min = found_min(a_list, index_min);
				(*a_list) = (*a_list)->next;
				nbr++;
			}
			(*a_list) = first_a;
		}
		if (nbr == ft_lstsize(*a_list))
			(*b_list)->t_pos = index_min->pos;
		else
			struct_t_pos_bis(a_list, b_list);
		(*b_list) = (*b_list)->next;
	}
	(*b_list) = first_b;
}

void	struct_cost_b(t_list **list)
{
	t_list	*first;
	int		size;
	int		move_nbr;

	first = (*list);
	size = ft_lstsize(*list);
	move_nbr = 0;
	while ((*list) != NULL)
	{
		if (move_nbr <= size / 2)
			(*list)->cost_b = move_nbr;
		else
			(*list)->cost_b = move_nbr - size;
		(*list) = (*list)->next;
		move_nbr++;
	}
	(*list) = first;
}

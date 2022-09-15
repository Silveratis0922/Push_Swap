/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:13:24 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/15 17:19:47 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while ((*a_list)->next != NULL && !((*b_list)->index > (*a_list)->index
			&& (*b_list)->index < (*a_list)->next->index))
	{
		(*a_list) = (*a_list)->next;
	}
	if ((*a_list)->next != NULL)
		(*b_list)->t_pos = (*a_list)->next->pos;
	else if ((*a_list)->next == NULL)
		(*b_list)->t_pos = 0;
	(*a_list) = first_a;
}

void	t_pos_again(t_list **a_list, t_list **b_list, int nbr, t_list *ind_min)
{
	t_list	*first;

	first = (*a_list);
	nbr = 0;
	while ((*a_list) != NULL && (*b_list)->index < (*a_list)->index)
	{
		ind_min = found_min(a_list, ind_min);
		(*a_list) = (*a_list)->next;
		nbr++;
	}
	(*a_list) = first;
	if (nbr == ft_lstsize(*a_list))
	{
		(*b_list)->t_pos = ind_min->pos;
	}
	else
		struct_t_pos_bis(a_list, b_list);
}

void	struct_t_pos(t_list **a_list, t_list **b_list)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*index_save;
	int		nbr;

	first_a = (*a_list);
	first_b = (*b_list);
	index_save = (*a_list);
	while ((*b_list) != NULL)
	{
		nbr = 0;
		while ((*a_list) != NULL && (*b_list)->index > (*a_list)->index)
		{
			index_save = found_max(a_list, index_save);
			(*a_list) = (*a_list)->next;
			nbr++;
		}
		(*a_list) = first_a;
		if (nbr == ft_lstsize(*a_list))
			(*b_list)->t_pos = index_save->pos + 1;
		else if (nbr != ft_lstsize (*a_list))
			t_pos_again(a_list, b_list, nbr, index_save);
		(*b_list) = (*b_list)->next;
	}
	(*b_list) = first_b;
}

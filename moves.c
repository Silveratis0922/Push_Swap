/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:30:17 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/02 15:16:46 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_swap(t_list **list, int write)
{
	t_list		*first;
	t_list		*second;
	t_list		*third;

	if (ft_lstsize(*list) > 1)
	{
		first = (*list);
		second = (*list)->next;
		third = (*list)->next->next;
		(*list) = second;
		second->next = first;
		first->next = third;
		struct_pos(list);
		struct_cost_b(list);
		write_action(write);
	}
}

void	lst_rotate(t_list **list, int write)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = (*list);
	second = (*list)->next;
	last = ft_lstlast(*list);
	last->next = first;
	first->next = NULL;
	(*list) = second;
	struct_pos(list);
	struct_cost_b(list);
	write_action(write);
}

void	lst_reverse_rotate(t_list **list, int write)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	first = (*list);
	while ((*list)->next->next != NULL)
		(*list) = (*list)->next;
	before_last = (*list);
	last = before_last->next;
	last->next = first;
	before_last->next = NULL;
	(*list) = last;
	struct_pos(list);
	struct_cost_b(list);
	write_action(write);
}

void	lst_push(t_list **input, t_list **output, int write)
{
	t_list	*first;
	t_list	*second;

	first = (*output);
	second = (*output)->next;
	ft_lstadd_front(input, first);
	(*output) = second;
	struct_pos(input);
	struct_pos(output);
	struct_cost_b(output);
	struct_cost_b(input);
	if (write == 3)
	{
		struct_t_pos(input, output);
		struct_cost_a(input, output);
	}
	write_action(write);
}

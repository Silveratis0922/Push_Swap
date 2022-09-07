/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:57:31 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/07 15:01:18 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_list(t_list **list, int *sorted_tab)
{
	int		i;
	t_list	*first;

	first = (*list);
	while ((*list) != NULL)
	{
		i = 0;
		while ((*list)->content != sorted_tab[i])
			i++;
		(*list)->index = i;
		(*list) = (*list)->next;
	}
	(*list) = first;
}

void	push_list(t_list **a_list, t_list **b_list)
{
	int	size;
	int	rest;

	size = ft_lstsize(*a_list);
	rest = size / 2;
	while (ft_lstsize(*a_list) > 3 && rest != 0)
	{
		if ((*a_list)->index >= size / 2)
			lst_rotate(a_list, 5);
		else
		{
			lst_push(b_list, a_list, 4);
			rest--;
		}
	}
	while (ft_lstsize(*a_list) != 3)
		lst_push(b_list, a_list, 4);
}

void	only_three(t_list **list)
{
	while (!((*list)->content < (*list)->next->content
			&& (*list)->next->content < (*list)->next->next->content))
	{
		if ((*list)->content > (*list)->next->content
			&& (*list)->content > (*list)->next->next->content)
			lst_rotate(list, 5);
		else if ((*list)->content < (*list)->next->next->content)
			lst_swap(list, 1);
		else if ((*list)->content < (*list)->next->content
			&& (*list)->content > (*list)->next->next->content)
			lst_reverse_rotate(list, 7);
	}
}

int	test_algo(t_list **a_list, t_list **b_list)
{
	int	*sort_tab;

	sort_tab = ft_sort_list(a_list);
	if (sort_tab == NULL)
		return (1);
//	printf("La mediane est :{%d}\n", sort_tab[ft_lstsize(*a_list) / 2]);
	ft_index_list(a_list, sort_tab);
	push_list(a_list, b_list);
	only_three(a_list);
	struct_t_pos(a_list, b_list);
	struct_cost_a(a_list, b_list);
	second_algo_part(a_list, b_list);
	mini_to_the_top(a_list);
	return (0);
}

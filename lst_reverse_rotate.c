/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:45:28 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/06 04:56:09 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_reverse_rotate(t_list **list)
{
	int	tmp;
	t_list	*first;
	t_list	*last;

	first = *list;	
	while ((*list)->next->next != NULL)
		*list = (*list)->next;
	last = *list;
	tmp = (*list)->next->content;
	free(last->next);
	last->next = NULL;
	ft_lstadd_front(&first, ft_lstnew(tmp));
	*list = first;
}

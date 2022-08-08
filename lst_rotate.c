/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:05 by tchantro          #+#    #+#             */
/*   Updated: 2022/08/06 04:32:07 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rotate(t_list **list)
{
	int	tmp;
	t_list	*first;

	first = (*list);
	tmp = first->content;
	first = first->next;
	ft_lstadd_back(list, ft_lstnew(tmp));
	free(*list);
	*list = first;
	//ft_lstadd_back(list, ft_lstnew(tmp));
}
